#!/bin/sh
PATH=/bin:/sbin:/usr/bin:/usr/sbin

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x "${PREFIX}/sbin/dhid" -a -f "${PREFIX}/etc/dhid.conf" ] && su -m dhis -c ${PREFIX}/sbin/dhid > /dev/null && echo -n ' dhid'
	;;
stop)
	killall dhid && echo -n ' dhid'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
