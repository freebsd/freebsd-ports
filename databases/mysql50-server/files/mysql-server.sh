#!/bin/sh

case "$1" in
	start)
		if [ -x %%PREFIX%%/bin/safe_mysqld ]; then
			%%PREFIX%%/bin/safe_mysqld --user=mysql > /dev/null & && echo -n ' mysqld'
		fi
		;;
	stop)
		/usr/bin/killall mysqld > /dev/null 2>&1 && echo -n ' mysqld'
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
