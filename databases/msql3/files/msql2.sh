#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/msql2d ] && su -f -l msql -c "exec ${PREFIX}/sbin/msql2d" > /dev/null 2>&1 & && echo -n ' msql2'
	;;
stop)
	killall msql2d && echo -n ' msql2d' && rm -f ${PREFIX}/etc/msql2/msql2d.pid
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
