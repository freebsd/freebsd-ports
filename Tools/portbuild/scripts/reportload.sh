#!/bin/sh
#
# For use on the client.  Start the load reporting service at system
# boot time.

if [ "$1" != "start" ]; then exit; fi

pb=/var/portbuild
arch=$(cat /etc/arch)
s=$pb/scripts/reportload

if [ -x $s ]; then
  $s ${arch} &
  echo -n ' reportload'
fi
