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
    kldload ${vmware_libdir}/modules/vmmon_${suffix}.ko
    if [ $networking -eq 1 ]; then
	sysctl net.link.ether.bridge_refresh && bridge="_bridge"
	kldload if_tap.ko
	if [ ! -e $dev_vmnet1 ]; then
		echo "$dev_vmnet1 does not exist!" >&2
		echo "Your VMware installation seems broken.  Please reinstall VMware port." >&2
		exit 255
	fi
	echo -n > $dev_vmnet1
	ifconfig vmnet1 $host_ip netmask $netmask
	if [ _$bridge != _ ]; then
	    sysctl -w net.link.ether.bridge_refresh=1
	    sysctl -w net.link.ether.bridge=1
	fi
    fi
    echo -n " VMware${bridge}" >&2
    ;;

stop)
    kldunload vmmon_${suffix}
    if [ $networking -eq 1 ]; then
	ifconfig vmnet1 down
	ifconfig vmnet1 delete $host_ip
	sysctl net.link.ether.bridge_refresh && bridge="_bridge"
	[ _$bridge != _ ] && sysctl -w net.link.ether.bridge_refresh=1
    fi
    ;;

*)
    echo "usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac
