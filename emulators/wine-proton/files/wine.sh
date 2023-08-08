#!/bin/sh

TARGET="$(realpath "$0")"

if [ -z "$WINESERVER" ] && [ -f "${TARGET}server32" ]
then
  export WINESERVER="${TARGET}server32"
fi

export GST_PLUGIN_SYSTEM_PATH_1_0="${TARGET%/*/*/*}/lib/gstreamer-1.0"

exec "${TARGET}.bin" "$@"
