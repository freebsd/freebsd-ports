#!/bin/sh
#
# Start the checkmachines script in the background, at system startup.

s=/var/portbuild/scripts/checkmachines

if [ -x $s ]; then
  $s &
  echo -n ' checkmachines'
fi
