#!/bin/sh
#---------------------------------------------------------------------
# 
#  I. Auto-detection of your Aureal Vortex sound card
#
# If for some reason this script fails to guess the type of your
# Aureal card correctly, you can manually override it here.
# Set this to 8810 (Vortex Advantage), 8820 (Vortex 1) or 8830
# (Vortex 2):
#
#CARD=8830
#
# II. VIA Apollo KX133 lock-up issue workaround
#
# If your AMD Athlon system is based on a VIA Apollo KX133 motherboard
# chipset, your system will most certainly lock up shortly after
# you start a playback. To work around this issue please uncomment
# this line:
#
#VIAKX133FIX=yes
#---------------------------------------------------------------------

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
		/sbin/kldload ${LIBDIR}/${DRIVERFILE}
		
		echo -n " aureal-kmod"

		# Increase PCI timeout for broken VIA Apollo KX133 chipsets
		# NOTE: This assumes your Aureal card is the pcm0 device
		if [ "$VIAKX133FIX" ]; then
			pcisel=`${PCICONF} -l 2>&- | grep ^pcm0 | awk -F: '{ gsub("^[^@]*@", ""); print $1":"$2":"$3 }'`
			if [ -z "$pcisel" ]; then
				echo " (WARNING: Soundcard PCI selector undetermined. Unable to install VIA KX133 workaround. Starting a playback will likely to lock-up your system!)"
				exit 64
			fi
			oldvalue=`${PCICONF} -r -b $pcisel 0x40 2>&- | sed 's/ *$//'`
			echo -n " (with VIA KX133 workaround: ${pcisel},0x40: ${oldvalue} -> "
			${PCICONF} -w -b $pcisel 0x40 0xff
			echo -n "`${PCICONF} -r -b $pcisel 0x40 2>&- | sed 's/ *$//'`)"
		fi
		;;
	stop)
		/sbin/kldunload ${DRIVERFILE}
		echo -n " aureal-kmod"
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac

