#!/bin/sh

kmoddir=@@PREFIX@@/modules
kmod=rtc.ko

case "$1" in
start)
	if [ -x $kmoddir/$kmod ]; then
	    echo -n ' rtc'
	    kldload $kmoddir/$kmod
	fi
	;;
stop)
	kldunload $kmod && echo -n ' rtc'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac
