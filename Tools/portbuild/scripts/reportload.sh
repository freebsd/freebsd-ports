#!/bin/sh
#
# For use on the client.  Start the load reporting service at system
# boot time.

if [ "$1" != "start" ]; then exit; fi

pb=/var/portbuild
s=$pb/scripts/reportload

echo -n ' chroot'
rm -rf $pb/*/chroot/*

if [ -x $s ]; then
  $s &
  echo -n ' reportload'
fi
