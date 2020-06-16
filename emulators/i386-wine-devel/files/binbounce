#!/bin/sh

TARGET="`realpath $0`"

LOCALBASE=${TARGET%/*}/..
BINNAME=${TARGET##*/}

if [ -z "$__BINBOUNCE_BOOTSTRAP" ]
then
  export LIBGL_DRIVERS_PATH=$LOCALBASE/lib32/dri
  if [ `uname -p` = i386 ]
  then
    export LD_LIBRARY_PATH="$LOCALBASE/lib32":"$LOCALBASE/lib32/wine":"$LD_LIBRARY_PATH":"$LOCALBASE/lib32/.libGL"
    export LD_LIBRARY_PATH_RPATH=y
  else
    export LD_32_LIBRARY_PATH="$LOCALBASE/lib32":"$LOCALBASE/lib32/wine":"$LD_32_LIBRARY_PATH":"$LOCALBASE/lib32/.libGL":/usr/lib32
    export LD_32_LIBRARY_PATH_RPATH=y
  fi
  export PATH="$LOCALBASE/bin32":"$PATH"
  export __BINBOUNCE_BOOTSTRAP="1"
fi

exec "$LOCALBASE/bin32/$BINNAME" "$@"
