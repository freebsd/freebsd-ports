#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 1
fi

case "$1" in
start)
	if [ -x ${PREFIX}/modules/cd9660.ko ]; then
		echo -n ' Big5-cd9660'
		kldload /usr/local/modules/cd9660.ko
	fi
	if [ -x ${PREFIX}/modules/msdos.ko ]; then
		echo -n ' Big5-msdos'
		kldload /usr/local/modules/msdos.ko
	fi
	# msdosfs.ko instead of msdos.ko after FreeBSD 5.0-CURRENT
	if [ -x ${PREFIX}/modules/msdosfs.ko ]; then
		echo -n ' Big5-msdosfs'
		kldload /usr/local/modules/msdosfs.ko
	fi
	if [ -x ${PREFIX}/modules/ntfs.ko ]; then
		echo -n ' Big5-ntfs'
		kldload /usr/local/modules/ntfs.ko
	fi
	;;
stop)
	kldunload -v -n cd9660 && echo -n ' Big5-cd9660'
	kldunload -v -n msdos && echo -n ' Big5-msdos'
	kldunload -v -n msdosfs && echo -n ' Big5-msdosfs'
	kldunload -v -n ntfs && echo -n ' Big5-ntfs'
	;;
*)
	echo "Usage: $0 {start|stop}" >&2
	exit 1
	;;
esac
