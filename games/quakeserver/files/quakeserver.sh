#!/bin/sh
#

case "$1" in
start)
	if [ -x %%PREFIX%%/quakeserver/unixded ]
	then
		echo %%PREFIX%%/quakeserver/qserver.sh | su -m quakerun \
			&& echo -n ' quakeserver'
	fi
	;;
stop)
	echo killall unixded | su -m quakerun && echo -n ' quakeserver'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
