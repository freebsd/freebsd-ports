#!/bin/sh

case "$1" in
start)
	[ -f %%PREFIX%%/etc/ircd/ircd.conf ] && %%PREFIX%%/sbin/ircd && echo -n ' ircd'
	;;
stop)
	killall ircd && echo -n ' ircd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
