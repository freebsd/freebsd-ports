#!/bin/sh
#

case "$1" in
start)
	if [ -x %%PREFIX%%/quakeserver/unixded ]
	then
		su nobody -c %%PREFIX%%/quakeserver/qserver.sh \
			&& echo -n ' quakeserver'
	fi
	;;
stop)
	su nobody -c %%PREFIX%%/quakeserver/qserver.sh && echo -n ' quakeserver'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
