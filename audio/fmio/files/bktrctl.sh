#!/bin/sh


if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi


case "$1" in
start)
	$PREFIX/bin/bktrctl 2>/dev/null >/dev/null && echo -n " bktrctl"
	;;
stop)
	/usr/bin/killall bktrctl && echo -n " bktrctl"
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
