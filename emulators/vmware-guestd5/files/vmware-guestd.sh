#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	exec 2>/dev/null
	ulimit -c 0
	if ${PREFIX}/sbin/checkvm >/dev/null; then
		${PREFIX}/sbin/vmware-guestd &
		echo -n ' vmware-guestd'
	fi
	;;
stop)
	exec 2>/dev/null
	ulimit -c 0
	if ${PREFIX}/sbin/checkvm >/dev/null; then
		killall vmware-guestd && echo -n ' vmware-guestd'
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
