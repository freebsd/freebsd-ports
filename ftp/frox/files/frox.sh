#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/frox -a -f ${PREFIX}/etc/frox.conf ]
	        grep -q '^ *# *FromInetd *yes' ${PREFIX}/etc/frox.conf && \
		${PREFIX}/sbin/frox && \
		echo -n ' frox'
	;;
stop)
	kill `cat /var/run/frox.pid` && echo -n ' frox'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
