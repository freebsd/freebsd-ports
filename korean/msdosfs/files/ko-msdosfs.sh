#!/bin/sh
# $FreeBSD$
#

module_dir=@@PREFIX@@/lib/ko-msdosfs

case $1 in
start)
    kldload ${module_dir}/msdos_ko.ko
    echo -n " msdosfs(ko)"
    ;;
stop)
    kldunload msdos_ko.ko
    ;;
*)
    echo "usage: `basename $0` {start|stop}"
    exit 1
    ;;
esac
