#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	if [ -x ${PREFIX}/sbin/msql3d ]; then
		su -f msql -c "exec ${PREFIX}/sbin/msql3d" > /dev/null 2>&1 &
		echo -n ' msql3'
	fi
	;;
stop)
	killall msql3d && echo -n ' msql3d' && rm -f ${PREFIX}/etc/msql3/msql3d.pid
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
