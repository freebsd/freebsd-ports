#!/bin/sh
MWAVEM_NAME="mwavem"
MWAVEM_PATH="/usr/local/bin/"
#
# -- START --
# $Id: init.freebsd.sh,v 1.1 2000/10/03 16:23:21 papowell Exp papowell $
# This file can be installed in /usr/local/etc/rc.d
#  as mwavem.sh
# Freebsd 4.x will run all files in this directory
#  with the suffix .sh as shell scripts
#

case "$1" in
    restart ) 
			$0 stop
			sleep 2
			$0 start
            ;;
    stop  )
            ;;
    start )
            echo -n ' internal modem'
            kldstat -n mwave 2>/dev/null >/dev/null || kldload /usr/local/share/mwavem/mwave.ko
            ${MWAVEM_PATH}${MWAVEM_NAME} > /dev/null &
            ;;
esac
