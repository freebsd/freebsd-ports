#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	if [ -x ${PREFIX}/sbin/opennap ]; then
		${PREFIX}/sbin/opennap > /dev/null 2>&1 &
		echo -n ' opennap'
	fi
	;;
stop)
	[ -r ${PREFIX}/share/opennap/pid ] && kill -15 `cat ${PREFIX}/share/opennap/pid` > /dev/null && rm -f ${PREFIX}/share/opennap/pid && echo -n ' opennap'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
