#!/bin/sh

kmod=@@PREFIX@@/modules/rtc.ko

if [ -x $kmod ]; then
    echo -n ' rtc'
    kldload $kmod
fi
