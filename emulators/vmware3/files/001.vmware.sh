#!/bin/sh
#
# Start or stop vmware
#
# $FreeBSD: /tmp/pcvs/ports/emulators/vmware3/files/Attic/001.vmware.sh,v 1.2 2004-07-08 08:26:34 silby Exp $

vmware_config_file=@@PREFIX@@/etc/vmware/config

if [ ! -e $vmware_config_file ]; then
    echo "$vmware_config_file does not exist!" >&2
    exit 255
fi

vmware_config() {
    cat $vmware_config_file | while read var eq value; do
	if [ "$1" = "$var" ]; then
	    ret=`expr "$value" : '"\(.*\)"$'`
	    echo ${ret:-$value}
	    break
	fi
    done
}

vmware=`vmware_config vmware.fullpath`
vmware_libdir=`vmware_config libdir`
networking=@@NETWORKING@@
dev_vmnet1=/dev/vmnet1
vmnet1_minor=@@VMNET1_MINOR@@

if [ ! -x $vmware ]; then
    echo "$vmware does not exist!" >&2
    exit 255
fi

if [ `sysctl -n hw.ncpu` -eq 1 ]; then
    suffix=up
else
    suffix=smp
fi

exec >/dev/null

case $1 in
start)
    kldstat -v | grep vmmon >/dev/null || kldload ${vmware_libdir}/modules/vmmon_${suffix}.ko
    kldstat -v | grep vmnet >/dev/null || kldload ${vmware_libdir}/modules/vmnet.ko
    if [ $networking -eq 1 ]; then
	kldstat -v | grep if_tap >/dev/null || kldload if_tap.ko
	if [ ! -e $dev_vmnet1 ]; then
		echo "$dev_vmnet1 does not exist!" >&2
		echo "Your VMware installation seems broken.  Please reinstall VMware port." >&2
		exit 255
	fi
	case $vmnet1_minor in
	0x*) vmnet1_minor=`(echo ibase=16;
		echo $vmnet1_minor | sed 's/^0x//' | tr a-f A-F) | bc` ;;
	esac
	vmnet_no=1
	bridge_no=1
	while true; do
	    vmnet=vmnet$vmnet_no
	    vmnet_no=`expr $vmnet_no + 1`
	    bridged=`vmware_config $vmnet.Bridged`
	    case $bridged in
	    '')   break ;;
	    '""') continue ;;
	    esac
	    host_ip=`vmware_config $vmnet.HostOnlyAddress`
	    netmask=`vmware_config $vmnet.HostOnlyNetMask`
	    if [ ! -c /dev/$vmnet ]; then
		rm -f /dev/$vmnet
		minor=`echo $vmnet1_minor $vmnet_no | \
		    awk '{ printf "0x%x", $1 - 1 + $2 - 1 }'`
		mknod /dev/$vmnet c 149 $minor
	    fi
	    echo -n > /dev/$vmnet 2>&1
	    ifconfig $vmnet $host_ip netmask $netmask
	    if [ X$bridged = XYES ]; then
		if [ X$host_ip = X0.0.0.0 ]; then
		    # XXX Still need to configure + delete to make it RUNNING
		    ifconfig $vmnet delete $host_ip
		fi
		bridge_interface=`vmware_config $vmnet.BridgeInterface`
		eval vmnet_bridge=\$vmnet_bridge_$bridge_interface
		if [ X$vmnet_bridge = X ]; then
		    kldstat -v | grep netgraph >/dev/null || kldload netgraph.ko
		    kldstat -v | grep ng_ether >/dev/null || kldload ng_ether.ko
		    kldstat -v | grep ng_bridge >/dev/null || kldload ng_bridge.ko
		    vmnet_bridge=vmnet_bridge$bridge_no
		    bridge_no=`expr $bridge_no + 1`
		    eval vmnet_bridge_$bridge_interface=$vmnet_bridge
		    ngctl mkpeer ${bridge_interface}: bridge lower link0
		    ngctl name ${bridge_interface}:lower ${vmnet_bridge}
		    ngctl connect ${vmnet_bridge}: ${bridge_interface}: link1 upper
		    ngctl msg ${bridge_interface}: setautosrc 0
		    ngctl msg ${bridge_interface}: setpromisc 1
		    eval ${vmnet_bridge}_linkno=2
		fi
		eval linkno=\$${vmnet_bridge}_linkno
		eval ${vmnet_bridge}_linkno=`expr $linkno + 1`
		ngctl connect ${vmnet_bridge}: ${vmnet}: link$linkno lower
		ngctl msg ${vmnet}: setautosrc 0
		ngctl msg ${vmnet}: setpromisc 1
	    fi
	done
    fi
    echo -n " VMware" >&2
    ;;

stop)
    kldunload vmmon_${suffix}
    if [ $networking -eq 1 ]; then
	vmnet_no=1
	bridge_no=1
	while true; do
	    vmnet=vmnet$vmnet_no
	    vmnet_no=`expr $vmnet_no + 1`
	    bridged=`vmware_config $vmnet.Bridged`
	    case $bridged in
	    '')   break ;;
	    '""') continue ;;
	    esac
	    host_ip=`vmware_config $vmnet.HostOnlyAddress`
	    ifconfig $vmnet down
	    if [ X$bridged = XYES ]; then
		if [ X$host_ip != X0.0.0.0 ]; then
		    ifconfig $vmnet delete $host_ip
		fi
		bridge_interface=`vmware_config $vmnet.BridgeInterface`
		eval vmnet_bridge=\$vmnet_bridge_$bridge_interface
		if [ X$vmnet_bridge = X ]; then
		    vmnet_bridge=vmnet_bridge$bridge_no
		    bridge_no=`expr $bridge_no + 1`
		    eval vmnet_bridge_$bridge_interface=$vmnet_bridge
		    ngctl msg ${bridge_interface}: setautosrc 1
		    ngctl msg ${bridge_interface}: setpromisc 0
		    ngctl shutdown ${vmnet_bridge}:
		fi
	    else
		ifconfig $vmnet delete $host_ip
	    fi
	done
	kldunload vmnet.ko
    fi
    ;;

*)
    echo "usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac
