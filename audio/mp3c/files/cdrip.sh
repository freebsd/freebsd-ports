#!/bin/sh
if  [ -f /tmp/mp3 ] ; then
        rm /tmp/mp3
fi
mkfifo /tmp/mp3
dagrab -v -n 64 -d $1 -f /tmp/mp3 $2 &

