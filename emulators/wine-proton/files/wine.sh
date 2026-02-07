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

export GST_PLUGIN_SYSTEM_PATH_1_0="${TARGET%/*/*/*}/lib/gstreamer-1.0"

exec "${TARGET}.bin" "$@"
