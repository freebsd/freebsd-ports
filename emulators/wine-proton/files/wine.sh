#!/bin/sh
TARGET="$(realpath "$0")"

if [ -z "$WINESERVER" ] && [ -f "${TARGET}server32" ]
then
  export WINESERVER="${TARGET}server32"
fi

export GST_PLUGIN_SYSTEM_PATH_1_0="${TARGET%/*/*/*}/lib/gstreamer-1.0"

# workaround for https://bugs.winehq.org/show_bug.cgi?id=50257
export LD_BIND_NOW=1
export LD_32_BIND_NOW=1

# workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=255336
if [ "$(uname -p)" = amd64 ]
then
  export LD_LIBMAP="libgcc_s.so.1=/lib/libgcc_s.so.1,${LD_LIBMAP}"
fi

exec "${TARGET}.bin" "$@"
