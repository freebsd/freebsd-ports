#!/bin/sh -e

if [ "$(id -u)" = 0 ]; then
  echo "Don't run this script as root!"
  exit 1
fi

I386_ROOT="${WINE_i386_ROOT:-$HOME/.i386-wine-pkg}"
ABI_FILE=/usr/lib32/libc.so.7

if [ ! -f $ABI_FILE ]; then
  echo "\"$ABI_FILE\" not found; exiting."
  exit 1
fi

if [ ! -d "$I386_ROOT/usr/share/keys/pkg" ]; then
  mkdir -p "$I386_ROOT/usr/share/keys"
  ln -s /usr/share/keys/pkg "$I386_ROOT/usr/share/keys/pkg"
fi

# Show what we're going to do, then do it.
echo pkg -o ABI_FILE=$ABI_FILE -o INSTALL_AS_USER=true -o RUN_SCRIPTS=false --rootdir "$I386_ROOT" "$@"
exec pkg -o ABI_FILE=$ABI_FILE -o INSTALL_AS_USER=true -o RUN_SCRIPTS=false --rootdir "$I386_ROOT" "$@"
