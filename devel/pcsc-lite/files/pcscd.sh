#!/bin/sh
# $FreeBSD$

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in

    start)
        if [ -x $PREFIX/sbin/pcscd ]; then
            $PREFIX/sbin/pcscd -c $PREFIX/etc/reader.conf
            echo -n ' pcscd'
        fi
    ;;

    stop)
        /usr/bin/killall pcscd && echo -n ' pcscd'
    ;;

    *)
        echo ""
        echo "Usage: `basename $0` { start | stop }"
        echo ""
        exit 64
    ;;
esac

