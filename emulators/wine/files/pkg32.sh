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

run_pkg32()
{
    # Show what we're going to do, then do it.
    echo pkg -o ABI_FILE=$ABI_FILE -o INSTALL_AS_USER=true -o RUN_SCRIPTS=false --rootdir "$I386_ROOT" "$@";
    pkg -o ABI_FILE=$ABI_FILE -o INSTALL_AS_USER=true -o RUN_SCRIPTS=false --rootdir "$I386_ROOT" "$@";
}

run_pkg32_old()
{
    shift

    # Show what we're going to do, then do it.
    echo pkg -o ABI="FreeBSD:14:i386" -o OSVERSION=1403000 -o INSTALL_AS_USER=true -o RUN_SCRIPTS=false --rootdir "$I386_ROOT" "$@";
    pkg -o ABI="FreeBSD:14:i386" -o OSVERSION=1403000 -o INSTALL_AS_USER=true -o RUN_SCRIPTS=false --rootdir "$I386_ROOT" "$@";
}

if [ $# -gt 0 ]; then
    case $1 in
    --old) run_pkg32_old "$@" ;;
    *) run_pkg32 "$@" ;;
    esac
else
    run_pkg32 "$@"
fi
