#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/${0##*/}\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 64
fi

if [ -r /etc/defaults/rc.conf ]; then
	. /etc/defaults/rc.conf
	source_rc_confs
elif [ -r /etc/rc.conf ]; then
	. /etc/rc.conf
fi

case "$1" in
start)
	case ${dcons_enable:-NO} in
	[Yy][Ee][Ss])
		/sbin/kldload ${PREFIX}/lib/dcons/dcons.ko && echo -n ' dcons'
		/sbin/kldload ${PREFIX}/lib/dcons/dcons_crom.ko && echo -n ' dcons_crom'
		/usr/sbin/fwcontrol -r
		;;
	esac
	;;
stop)
	case ${dcons_enable:-NO} in
	[Yy][Ee][Ss])
		/sbin/kldunload dcons & echo -n ' dcons'
		/sbin/kldunload dcons_crom & echo -n ' dcons_crom'
		;;
	esac
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
