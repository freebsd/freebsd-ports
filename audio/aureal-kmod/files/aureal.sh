#!/bin/sh

# If for some reason this script fails to guess the type of your
# Aureal card correctly, you can manually override it here.
# Set this to 8810 (Vortex Advantage), 8820 (Vortex 1) or 8830
# (Vortex 2):
#
#CARD=8830
#

PCICONF="/usr/sbin/pciconf"

if [ -z "${CARD}" -a -x ${PCICONF} ]; then
	if [ "`${PCICONF} -l 2>&- | grep 0x000312eb`" ]; then
		CARD=8810
	elif [ "`${PCICONF} -l 2>&- | grep 0x000112eb`" ]; then
		CARD=8820
	elif [ "`${PCICONF} -l 2>&- | grep 0x000212eb`" ]; then
		CARD=8830
	fi
fi

if [ -z "${CARD}" ]; then
	echo "Unable to determine your Aureal card type -" \
		"override it manually in $0" >&2
	exit 255
fi

PREFIX=%%PREFIX%%
LIBDIR=${PREFIX}/lib/au88x0
DRIVERFILE=snd_au${CARD}.ko

case "$1" in
	start)
		if [ ! -f ${LIBDIR}/${DRIVERFILE} ]; then
			echo ""
			echo "${LIBDIR}/${DRIVERFILE} for ${CARD} not found!"
			echo ""
			exit 64
		fi
		/sbin/kldload snd_pcm.ko
		/sbin/kldload ${LIBDIR}/${DRIVERFILE}
		echo -n " aureal-kmod"
		;;
	stop)
		/sbin/kldunload ${DRIVERFILE}
		/sbin/kldunload snd_pcm.ko
		echo -n " aureal-kmod"
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
