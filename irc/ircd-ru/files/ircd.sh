#!/bin/sh

PREFIX=$(expr $0 : "\(/.*/\)etc/rc\.d/$(basename $0)\$")

IRCD=${PREFIX}sbin/ircd

case "$1" in
start)
	if [ -x $IRCD ]; then
		$IRCD -u ircd -g ircd >/dev/null 2>&1
		echo -n ' ircd'
	fi
	;;
stop)
	kill `cat /var/run/ircd-ru/ircd.pid` >/dev/null 2>&1
	echo -n ' ircd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
