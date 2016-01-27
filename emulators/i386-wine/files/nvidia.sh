#!/bin/sh
# Copyright 2010 to 2015 David Naylor <dbn@FreeBSD.org>
# Copyright 2012 Jan Beich <jbeich@tormail.org>
#       All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#   1. Redistributions of source code must retain the above copyright notice,
#      this list of conditions and the following disclaimer.
#
#   2. Redistributions in binary form must reproduce the above copyright notice,
#      this list of conditions and the following disclaimer in the documentation
#      and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY David Naylor ``AS IS'' AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
# EVENT SHALL David Naylor OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
# OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
# EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# The views and conclusions contained in the software and documentation are
# those of the authors and should not be interpreted as representing official
# policies, either expressed or implied, of David Naylor.

# Version 1.0 - 2010/05/28
#  - initial release
# Version 1.1 - 2010/10/04
#  - add support for 256 driver series
#  - use passive connections for FTP
#  - allow resuming of downloads if they were interrupted
#  - add license and copyright notice
# Version 1.2 - 2010/10/17
#  - try to save the NVIDIA tarball under $PORTSDIR/distfiles
#  - obay $PREFIX
#  - extract files directly to destination (avoids using /tmp)
# Version 1.3 - 2010/11/02
#  - add support for future driver series
# Version 1.4 - 2011/05/23
#  - add support for legacy drivers
# Version 1.5 - 2011/10/23
#  - add support for no-fetch mode
#  - backup the original openGL.so.1 library
# Version 1.6 - 2012/06/06
#  - add support for pkgng
# Version 1.7 - 2012/06/23
#  - make nVidia detection more robust
#  - allow mixed pkg/pkgng operation
# Version 1.8 - 2012/07/02
#  - fix mixed pkg/pkgng operation
# Version 1.9 - 2012/10/31
#  - fix permission of extracts files
# Version 1.10 - 2013/05/06
#  - s/wine-fbsd64/i386-wine/g
#  - fix unwanted failures due to `set -e`
# Version 1.11 - 2013/05/26
#  - install libGL.so.1 to ${PREFIX}/lib32/.nvidia and link to it
#  - add deinstall option
# Version 1.12 - 2013/11/03
#  - add detection for i386-wine-devel
# Version 1.13 - 2014/08/05
#  - add detection for i386-wine-compholio
# Version 1.14 - 2014/12/26
#  - gracefully handle a corrupt nVidia tarball
#  - provide checksum and size information for nVidia tarball
# Version 1.15 - 2015/03/10
#  - handle nvidia-driver with package name suffix
#  - handle i386-wine with arbitary package name suffix
#  - remove support for old pkg_ tools

set -e

PORTSDIR=${PORTSDIR:-/usr/ports}
PREFIX=${PREFIX:-/usr/local}
DISTDIR=${DISTDIR:-${PORTSDIR}/distfiles}

if [ -d $DISTDIR ]
then
  cd $DISTDIR
  NO_REMOVE_NVIDIA="yes"
else
  cd /tmp/
fi

terminate() {

  echo "!!! $2 !!!"
  echo "Terminating..."
  exit $1

}

args=`getopt dn $*`
if [ $? -ne 0 ]
then
  echo "Usage: $0 [-n]"
  exit 7
fi
set -- $args
while true
do
  case $1 in
    -d)
      rm -f ${PREFIX}/lib32/libGL.so.1 
      rm -f ${PREFIX}/lib32/libGLcore.so.1 ${PREFIX}/lib32/libnvidia-tls.so.1 
      rm -f ${PREFIX}/lib32/libnvidia-glcore.so.1 ${PREFIX}/lib32/libnvidia-tls.so.1
      rm -rf  ${PREFIX}/lib32/.nvidia/
      if [ -d ${PREFIX}/lib32/.libGL-new ]
      then
        ln -s .libGL-new/libGL.so.1 ${PREFIX}/lib32/libGL.so.1
      else
        ln -s .libGL/libGL.so.1 ${PREFIX}/lib32/libGL.so.1
      fi
      exit 0
      ;;
    -n)
      NO_FETCH=yes
      ;;
    --)
      shift
      break
      ;;
  esac
  shift
done

version() {
  local ret pkg="$1"
  if [ -f "/usr/local/sbin/pkg" ]
  then
    ret=`pkg query -g '%v' "$pkg" || true`
  fi

  # installed manually or failed to register
  if [ -z "$ret" ] && [ "$pkg" = "nvidia-driver*" ]
  then
    ret=`sed -n "s/.*Version: //p" 2> /dev/null \
      $PREFIX/share/doc/NVIDIA_GLX-1.0/README || true`
  fi
  echo "$ret"
}

[ `whoami` = root ] \
  || terminate 254 "This script should be run as root"

echo "===> Patching i386-wine to work with x11/nvidia-driver:"

if [ -z "${WINE}" ]
then
  WINE=`version 'i386-wine*'`
fi
[ -n "$WINE" ] \
  || terminate 255 "Unable to detect i386-wine, please install first"
echo "=> Detected i386-wine: ${WINE}"

NV=`version 'nvidia-driver*'`
[ -n "$NV" ] \
  || terminate 1 "Unable to detect nvidia-driver, please install first"
echo "=> Detected nvidia-driver: ${NV}"

NVIDIA=${NV}
NV=`echo ${NV} | cut -f 1 -d _ | cut -f 1 -d ,`

if [ ! -f NVIDIA-FreeBSD-x86-${NV}.tar.gz ] || !(tar -tf NVIDIA-FreeBSD-x86-${NV}.tar.gz > /dev/null 2>&1)
then
  [ -n "$NO_FETCH" ] \
    && terminate 8 "NVIDIA-FreeBSD-x86-${NV}.tar.gz unavailable"
  echo "=> Downloading NVIDIA-FreeBSD-x86-${NV}.tar.gz from ftp://download.nvidia.com..."
  rm -f NVIDIA-FreeBSD-x86-${NV}.tar.gz
  fetch -apRr ftp://download.nvidia.com/XFree86/FreeBSD-x86/${NV}/NVIDIA-FreeBSD-x86-${NV}.tar.gz \
    || terminate 2 "Failed to download NVIDIA-FreeBSD-x86-${NV}.tar.gz"
  echo "=> Downloaded NVIDIA-FreeBSD-x86-${NV}.tar.gz"
  echo "Please check the following information against /usr/ports/x11/nvidia-driver/distinfo"
  sha256 NVIDIA-FreeBSD-x86-${NV}.tar.gz
  echo "SIZE (NVIDIA-FreeBSD-x86-${NV}.tar.gz) = `stat -f "%z" NVIDIA-FreeBSD-x86-${NV}.tar.gz`"
fi

echo "=> Extracting NVIDIA-FreeBSD-x86-${NV}.tar.gz to $PREFIX/lib32..."
EXTRACT_LIST="libGL.so.1"
case $NV in
  195*|173*|96*|71*)
    EXTRACT_LIST="$EXTRACT_LIST libGLcore.so.1 libnvidia-tls.so.1"
    ;;
  *)
    EXTRACT_LIST="$EXTRACT_LIST libnvidia-glcore.so.1 libnvidia-tls.so.1"
    ;;
esac

EXTRACT_ARGS="--no-same-owner --no-same-permissions --strip-components 2 -C $PREFIX/lib32"
for i in $EXTRACT_LIST
do
  EXTRACT_ARGS="$EXTRACT_ARGS --include NVIDIA-FreeBSD-x86-${NV}/obj/$i"
done
umask 0333
tar $EXTRACT_ARGS -xvf NVIDIA-FreeBSD-x86-${NV}.tar.gz \
  || terminate 3 "Failed to extract NVIDIA-FreeBSD-x86-${NV}.tar.gz"
mkdir -m 0755 -p ${PREFIX}/lib32/.nvidia \
  || terminate 9 "Failed to create .nvidia shadow directory"
mv ${PREFIX}/lib32/libGL.so.1 ${PREFIX}/lib32/.nvidia/ \
  || terminate 10 "Failed to move libGL.so.1 to .nvidia/ shadow directory"
ln -s .nvidia/libGL.so.1 ${PREFIX}/lib32/libGL.so.1 \
  || terminate 11 "Failed to link to .nvidia/libGL.so.1 in the shadow directory"

echo "=> Cleaning up..."
[ -n "$NO_REMOVE_NVIDIA" ] || rm -vf NVIDIA-FreeBSD-x86-${NV}.tar.gz \
  || terminate 6 "Failed to remove files"

echo "===> i386-wine-${WINE} successfully patched for nvidia-driver-${NVIDIA}"
