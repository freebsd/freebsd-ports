#!/bin/sh

case "$1" in
	start)
		/sbin/ldconfig -m %%PREFIX%%/lib/mrproject
		/sbin/ldconfig -m %%PREFIX%%/lib/mrproject/views
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
