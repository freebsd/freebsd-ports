#!/bin/sh

case "$1" in
start)
	[ -x /usr/local/sbin/ircd ] \
	&& /usr/local/sbin/ircd >/dev/null 2>&1 \
	&& echo -n " ircd"
	;;
stop)
	killall ircd && echo -n ' ircd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
