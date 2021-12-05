#!/bin/sh -e

TARGET="$(realpath "$0")"
PREFIX="${TARGET%/*/*}"
LOCALBASE="${PREFIX}"

I386_ROOT="${WINE_i386_ROOT:-$HOME/.i386-wine-pkg}"

if [ ! -f "$I386_ROOT/$PREFIX/bin/wine" ]
then
  printf "%s doesn't exist!\n\n" "$I386_ROOT/$PREFIX/bin/wine"
  printf "Try installing 32-bit Wine with\n\t%s\n" "$PREFIX/share/wine/pkg32.sh install wine mesa-dri"
  exit 1
fi

WINE32_VERSION=$(env -u WINELOADERNOEXEC "$I386_ROOT/$PREFIX/bin/wine" --version)
WINE64_VERSION=$(env -u WINELOADERNOEXEC "${TARGET}64" --version)
if [ "$WINE32_VERSION" != "$WINE64_VERSION" ]
then
  printf "wine [%s] and wine64 [%s] versions do not match!\n\n" "$WINE32_VERSION" "$WINE64_VERSION"
  printf "Try updating 32-bit wine with\n\t%s\n" "$PREFIX/share/wine/pkg32.sh upgrade"
  exit 1
fi

export LIBGL_DRIVERS_PATH="${LIBGL_DRIVERS_PATH:+$LIBGL_DRIVERS_PATH:}$LOCALBASE/lib/dri:$LOCALBASE/lib32/dri:$I386_ROOT/$LOCALBASE/lib/dri"
export LD_32_LIBRARY_PATH="${LD_32_LIBRARY_PATH:+$LD_32_LIBRARY_PATH:}$I386_ROOT/$PREFIX/lib/wine:$LOCALBASE/lib32:$I386_ROOT/$LOCALBASE/lib"
for d in "$I386_ROOT/$LOCALBASE"/llvm*/lib
do
  if [ -d "$d" ]
  then
    export LD_32_LIBRARY_PATH="$LD_32_LIBRARY_PATH:$d"
  fi
done
export LD_32_LIBRARY_PATH_RPATH=y
export LD_32_LIBMAP="
libgcc_s.so.1 /usr/lib32/libgcc_s.so.1
$LOCALBASE/lib/libvulkan_intel.so  $I386_ROOT/$LOCALBASE/lib/libvulkan_intel.so
$LOCALBASE/lib/libvulkan_radeon.so $I386_ROOT/$LOCALBASE/lib/libvulkan_radeon.so
$LD_32_LIBMAP"

if [ -z "$WINE_NO_WOW64" ]
then
  export WINESERVER="${TARGET}server"
fi

exec "$I386_ROOT/$PREFIX/bin/wine" "$@"
