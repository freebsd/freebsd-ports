#!/bin/sh

##
## workaround for
## * https://github.com/chipsalliance/yosys-f4pga-plugins/issues/527
##
##

if [ "$1" != "-D" ]; then
	exit 1
fi

#/usr/bin/install -m 0644 $2 ${DESTDIR}$3
/usr/bin/install $2 $3
