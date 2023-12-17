#!/bin/sh

TARGET="$(realpath "$0")"

if [ -z "$WINESERVER" ]
then
  if [ -f "${TARGET%/*}/wineserver" ]
  then
    export WINESERVER="${TARGET%/*}/wineserver"
  fi
  if [ -f "${TARGET%/*}/wineserver32" ]
  then
    export WINESERVER="${TARGET%/*}/wineserver32"
  fi
fi

# Workaround for https://bugs.winehq.org/show_bug.cgi?id=50257
export LD_BIND_NOW=1
export LD_32_BIND_NOW=1

exec "${TARGET}.bin" "$@"
