#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	if [ -x ${PREFIX}/sbin/conserver -a -f ${PREFIX}/etc/conserver.cf ]; then
		${PREFIX}/sbin/conserver -d -n ; echo -n ' conserver'
	fi
	;;
stop)
	killall conserver && echo -n ' conserver'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
