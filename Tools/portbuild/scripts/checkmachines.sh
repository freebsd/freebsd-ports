#!/bin/sh

s=/a/asami/portbuild/scripts/checkmachines

if [ -x $s ]; then
  $s &
  echo -n ' checkmachines'
fi
