#!/bin/sh

PREFIX=%%PREFIX%%
IFFILE=${PREFIX}/etc/gdomap_if
PIDFILE=/var/run/gdomap.pid
GNUSTEP_SYSTEM_ROOT=${PREFIX}/GNUstep/System

case "$1" in
start)
	if [ -e ${GNUSTEP_SYSTEM_ROOT}/Makefiles/GNUstep.sh ]; then
		. ${GNUSTEP_SYSTEM_ROOT}/Makefiles/GNUstep.sh
		if [ -x ${GNUSTEP_SYSTEM_ROOT}/Tools/${GNUSTEP_HOST_CPU}/${GNUSTEP_HOST_OS}/gdomap ]; then
			rm -f ${PIDFILE}
			${GNUSTEP_SYSTEM_ROOT}/Tools/${GNUSTEP_HOST_CPU}/${GNUSTEP_HOST_OS}/gdomap -a ${IFFILE} -I ${PIDFILE}
			echo -n ' GNUstep'
		fi
	fi
	;;
stop)
	[ -r ${PIDFILE} ] && kill $(cat ${PIDFILE}) && echo -n ' GNUstep'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
