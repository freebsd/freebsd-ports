#!/bin/sh

s=/a/asami/portbuild/scripts/reportload

if [ -x $s ]; then
  $s &
  echo -n ' reportload'
fi
