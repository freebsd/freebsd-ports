#!/bin/sh
#
# $FreeBSD$

vjed="/usr/local/vje30/bin/vjed"

case "$1" in
start)
	if [ -x $vjed ] ; then
		echo -n ' vje30:'
		$vjed &
	fi
	;;
stop)
	if killall vjed 2>/dev/null; then
		echo -n ' vje30'
	else
		echo -n ' vje30: not running'
 	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
