#!/bin/sh
if [ -d /var/run/emacs/lock ]
then
    rm -f /var/run/emacs/lock/*
else
    mkdir -p /var/run/emacs/lock
fi
chmod 1777 /var/run/emacs/lock
exit 0

