#!/bin/sh

if [ -f /usr/local/vje30/.version ] \
 && grep -qw 'FREE TRIAL VERSION' /usr/local/vje30/.version \
 && [ X"$1" != X"-f" ]; then
    echo ""
    echo "esecanna:"
    echo "  Using VJE-Delta 3.0 trial, it is unable to connect to vjed on startup."
    echo "  Please execute \`$0 -f' manually"
    echo "  after once you run vje."
    exit
fi

esecannaserver="!!PREFIX!!/sbin/esecannaserver"

if [ -x $esecannaserver ]; then
    rm -f /tmp/.iroha_unix/IROHA
    echo -n ' esecannai: '
    $esecannaserver
fi
