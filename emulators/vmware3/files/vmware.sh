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
exec >/dev/null

case $1 in
start)
    kldload ${vmware_dir}/lib/modules/vmmon.ko
    if [ $networking -eq 1 ]; then
	kldload ${vmware_dir}/lib/modules/vmnet.ko
	echo -n >/dev/vmnet1
	ifconfig vmnet1 $host_ip netmask $netmask
    fi
    echo -n " VMware" >/dev/tty
    ;;

stop)
    kldunload vmmon
    if [ $networking -eq 1 ]; then
	ifconfig vmnet1 down
	ifconfig vmnet1 delete $host_ip
	kldunload vmnet
    fi
    ;;

*)
    echo "usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac
