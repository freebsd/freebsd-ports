#!/bin/sh
# $FreeBSD$

module_dir=@@PREFIX@@/lib/ja-msdosfs

case $1 in
start)
    kldload ${module_dir}/msdos_ja.ko
    echo -n " JA-MSDOSFS"
    ;;
stop)
    kldunload msdos_ja.ko
    ;;
*)
    echo "usage: `basename $0` {start|stop}"
    exit 1
    ;;
esac
