#!/bin/sh

PREFIX=%%PREFIX%%
MAJOR=%%MAJOR%%

if mount -p | awk '{print $3}'| grep -q devfs ; then
  HAVEDEVFS=YES
else
  HAVEDEVFS=NO
fi

case "$1" in
  stop)
    if [ "${HAVEDEVFS}" = "NO" ]; then
      rm -f /dev/cual0 /dev/cuail0 /dev/cuall0 /dev/ttyl0 /dev/ttyil0 /dev/ttyll0
    fi
    kldstat -n ltmdm 2>/dev/null >/dev/null && kldunload ltmdm
    ;;
  start|restart)
    $0 stop
    sleep 1
    if [ "${HAVEDEVFS}" = "NO" ]; then
      umask 7
      mknod /dev/cual0  c ${MAJOR} 128 uucp:dialer
      mknod /dev/cuail0 c ${MAJOR} 160 uucp:dialer
      mknod /dev/cuall0 c ${MAJOR} 192 uucp:dialer
      umask 77
      mknod /dev/ttyl0  c ${MAJOR} 0  root:wheel
      mknod /dev/ttyil0 c ${MAJOR} 32 root:wheel
      mknod /dev/ttyll0 c ${MAJOR} 64 root:wheel
    fi

    kldload ${PREFIX}/share/ltmdm/ltmdm.ko
    echo -n ' ltmdm'
    ;;
esac
