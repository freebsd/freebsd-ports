#!/bin/sh

b=/a/asami/portbuild
s=$b/scripts/reportload

echo -n ' chroot'
rm -rf $b/*/chroot/*

if [ -x $s ]; then
  $s &
  echo -n ' reportload'
fi
