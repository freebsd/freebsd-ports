#!/bin/sh
wxgserver=!!PREFIX!!/sbin/wxgserver

case "$1" in
start)
	if [ -f $wxgserver ]; then
		rm -f /var/run/canna/Canna.pid
		mkdir -p /var/run/canna
		chown bin:bin /var/run/canna
		echo -n ' WXG'
		$wxgserver &
	fi
	;;
stop)
	!!PREFIX!!/sbin/cannakill && echo -n ' WXG'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
