#!/bin/sh

case "$1" in
start)
	[ -x "__PREFIX__/dhis/bin/dhisd" ] && __PREFIX__/dhis/bin/dhisd > /dev/null && echo -n ' dhisd'
	;;
stop)
	killall dhisd && echo -n ' dhisd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
