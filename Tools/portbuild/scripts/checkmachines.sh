#!/bin/sh

s=/var/portbuild/scripts/checkmachines

if [ -x $s ]; then
  $s &
  echo -n ' checkmachines'
fi
