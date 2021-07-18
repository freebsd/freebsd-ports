#!/bin/sh -e
TARGET="$(realpath "$0")"
PREFIX="${TARGET%/*/*}"
LOCALBASE="${PREFIX%/*}"

I386_ROOT="${WINE_i386_ROOT:-$HOME/.i386-wine-pkg}"

export LIBGL_DRIVERS_PATH="${LIBGL_DRIVERS_PATH:+$LIBGL_DRIVERS_PATH:}$LOCALBASE/lib/dri:$LOCALBASE/lib32/dri:$I386_ROOT/$LOCALBASE/lib/dri"
export LD_32_LIBRARY_PATH="${LD_32_LIBRARY_PATH:+$LD_32_LIBRARY_PATH:}$I386_ROOT/$PREFIX/lib/wine:$LOCALBASE/lib32:$I386_ROOT/$LOCALBASE/lib:$I386_ROOT/$LOCALBASE/llvm10/lib:$I386_ROOT/$LOCALBASE/llvm11/lib"
export LD_32_LIBRARY_PATH_RPATH=y

if [ -z "$WINE_NO_WOW64" ]
then
  export PATH="${TARGET%/*}:${PATH}"
  export WINESERVER="${TARGET}server"
fi

if [ ! -f "$I386_ROOT/$PREFIX/bin/wine" ]
then
  printf "%s doesn't exist!\n\n" "$I386_ROOT/$PREFIX/bin/wine"
  printf "Try installing 32-bit wine with\n\t%s\n" "$PREFIX/bin/pkg32.sh install wine-proton mesa-dri"
  exit 1
fi

WINE32_VERSION=$(env -u WINELOADERNOEXEC "$I386_ROOT/$PREFIX/bin/wine" --version)
WINE64_VERSION=$(env -u WINELOADERNOEXEC "${TARGET}64" --version)
if [ "$WINE32_VERSION" != "$WINE64_VERSION" ]
then
  printf "wine [%s] and wine64 [%s] versions do not match!\n\n" "$WINE32_VERSION" "$WINE64_VERSION"
  printf "Try updating 32-bit wine with\n\t%s\n" "$PREFIX/bin/pkg32.sh upgrade"
  exit 1
fi

exec "$I386_ROOT/$PREFIX/bin/wine" "$@"
