#!/bin/sh

case "$1" in
start)
	[ -x "__PREFIX__/sbin/dhisd" ] && __PREFIX__/sbin/dhisd > /dev/null && echo -n ' dhisd'
	;;
restart)
	killall -HUP dhisd && echo -n 'dhisd restarted'
	;;
stop)
	killall dhisd && echo -n ' dhisd'
	;;
*)
	echo "Usage: `basename $0` {start|restart|stop}" >&2
	;;
esac

exit 0
