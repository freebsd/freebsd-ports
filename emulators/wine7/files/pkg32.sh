#!/bin/sh -e

if [ "$(id -u)" = 0 ]
then
  echo "Don't run this script as root!"
  exit 1
fi

I386_ROOT="${WINE_i386_ROOT:-$HOME/.i386-wine-pkg}"

if [ ! -d "$I386_ROOT/usr/share/keys/pkg" ]
then
  mkdir -p "$I386_ROOT/usr/share/keys"
  ln -s /usr/share/keys/pkg "$I386_ROOT/usr/share/keys/pkg"
fi

ABI=$(pkg config ABI | sed s/amd64/i386/)
# Show what we're going to do, then do it.
echo pkg -o ABI="$ABI" -o INSTALL_AS_USER=true -o RUN_SCRIPTS=false --rootdir "$I386_ROOT" "$@"
exec pkg -o ABI="$ABI" -o INSTALL_AS_USER=true -o RUN_SCRIPTS=false --rootdir "$I386_ROOT" "$@"
