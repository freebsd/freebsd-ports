#!/bin/sh
#
# Start or stop vmware
#
# $FreeBSD$

vmware_dir=@@PREFIX@@/lib/vmware
networking=@@NETWORKING@@
host_ip=@@HOST_IP@@
netmask=@@NETMASK@@

[ -x $vmware_dir/bin/vmware ] || exit

if [ `sysctl -n hw.ncpu` -eq 1 ]; then
    suffix=up
else
    suffix=smp
fi

exec >/dev/null

case $1 in
start)
    kldload ${vmware_dir}/lib/modules/vmmon_${suffix}.ko
    if [ $networking -eq 1 ]; then
	sysctl net.link.ether.bridge_refresh && bridge="_bridge"
	kldload if_tap.ko
	echo -n >@@LINUXBASE@@/dev/vmnet1
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
