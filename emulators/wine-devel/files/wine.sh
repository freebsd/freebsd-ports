#!/bin/sh

case "$1" in
	start)
		/sbin/ldconfig -m %%PREFIX%%/lib/wine
		;;
	stop)
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
