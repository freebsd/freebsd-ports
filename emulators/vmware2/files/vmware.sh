#!/bin/sh
#
# Start or stop vmware
#
# $FreeBSD$

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
bridged=@@BRIDGED@@
bridge_interface=@@BRIDGE_INTF@@
host_ip=`vmware_config vmnet1.HostOnlyAddress`
netmask=`vmware_config vmnet1.HostOnlyNetMask`
dev_vmnet1=@@LINUXBASE@@/dev/vmnet1

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
    if [ $networking -eq 1 ]; then
	kldstat -v | grep if_tap >/dev/null || kldload if_tap.ko
	if [ ! -e $dev_vmnet1 ]; then
		echo "$dev_vmnet1 does not exist!" >&2
		echo "Your VMware installation seems broken.  Please reinstall VMware port." >&2
		exit 255
	fi
	(echo -n > $dev_vmnet1) 2>/dev/null || \
	    echo -n > /dev/vmnet1 2>&1
    	echo -n > /dev/vmnet1 2>&1 || true
	echo -n > $dev_vmnet1 2>&1
	ifconfig vmnet1 $host_ip netmask $netmask
	if [ X$bridged = XYES ]; then
	    kldstat -v | grep netgraph >/dev/null || kldload netgraph.ko
	    kldstat -v | grep ng_ether >/dev/null || kldload ng_ether.ko
	    kldstat -v | grep ng_bridge >/dev/null || kldload ng_bridge.ko
	    ngctl mkpeer vmnet1: bridge lower link0
	    ngctl name vmnet1:lower vmnet_bridge
	    ngctl connect vmnet_bridge: ${bridge_interface}: link1 lower
	    ngctl connect vmnet_bridge: ${bridge_interface}: link2 upper
	    ngctl msg ${bridge_interface}: setautosrc 0
	    ngctl msg ${bridge_interface}: setpromisc 1
	    ngctl msg vmnet1: setautosrc 0
	    ngctl msg vmnet1: setpromisc 1
	fi
    fi
    echo -n " VMware" >&2
    ;;

stop)
    kldunload vmmon_${suffix}
    if [ $networking -eq 1 ]; then
	ifconfig vmnet1 down
	ifconfig vmnet1 delete $host_ip
	if [ X$bridged = XYES ]; then
	    ngctl shutdown vmnet_bridge:
	    ngctl msg ${bridge_interface}: setautosrc 1
	    ngctl msg ${bridge_interface}: setpromisc 0
	fi
    fi
    ;;

*)
    echo "usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac
