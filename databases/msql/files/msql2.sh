#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/bin/msql2d ] && su -l msql -c 'exec ${PREFIX}/bin/msql2d' > /dev/null 2>&1 & && echo -n ' msql2'
	;;
stop)
	killall msql2d && echo -n ' msql2d'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
