#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
	case $(dirname $0) in
	.)
	    PREFIX=$(pwd)
	    ;;
	*)
	    echo "$0: Cannot determine the PREFIX" >&2
	    exit 1
	    ;;
esac
fi

args="${PREFIX}/etc/ncftpd/general.cf ${PREFIX}/etc/ncftpd/domain.cf"

case "$1" in
start)
        if [ -x ${PREFIX}/sbin/ncftpd ]; then
		echo -n ' ncftpd'
		${PREFIX}/sbin/ncftpd -d $args
	fi
        ;;
stop)
        killall ncftpd && echo -n ' ncftpd'
        ;;
*)
        echo "Usage: `basename $0` {start|stop}" >&2
        exit 64
        ;;
esac

exit 0
