#!/bin/sh

case "$1" in
	start)
		if [ -x %PREFIX%/sbin/totd ]; then
			%PREFIX%/sbin/totd && echo -n ' totd'
		fi
	;;

	stop)
		/usr/bin/killall totd && echo -n ' totd'
	;;
	
	*)
		echo "Usage: `basename $0` { start | stop }"
		exit 64
	;;
esac
