#!/bin/sh

# $FreeBSD$

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
	killall -TERM conserver && echo -n ' conserver'
	;;
restart)
	$0 stop
	$0 start
	;;
status|stat)
	ps -auxww | egrep '(conserver|console)' | egrep -v "($0|egrep)"
	;;
*)
	echo "Usage: `basename $0` {start|stop|restart|status}" >&2
	;;
esac

exit 0
