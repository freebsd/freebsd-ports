#!/bin/sh

kmod=@@PREFIX@@/modules/rtc.ko

case "$1" in
start)
	if [ -x $kmod ]; then
	    echo -n ' rtc'
	    kldload $kmod
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
