#!/bin/sh

PREFIX=%%PREFIX%%

case "$1" in
  restart)
    $0 stop
    sleep 2
    $0 start
    ;;
  stop)
    kldstat -n ixj 2>/dev/null >/dev/null && kldunload ixj
    ;;
  start)
    echo -n ' ixj'
    rm -f /dev/phone0 /dev/phone1 /dev/phone2 /dev/phone3
    mknod /dev/phone0 c 155 0
    mknod /dev/phone1 c 155 1
    mknod /dev/phone2 c 155 2
    mknod /dev/phone3 c 155 3
    chmod 660 /dev/phone0
    chmod 660 /dev/phone1
    chmod 660 /dev/phone2
    chmod 660 /dev/phone3

    kldstat -n ixj 2>/dev/null >/dev/null || kldload $PREFIX/modules/ixj.ko
    ;;
esac
