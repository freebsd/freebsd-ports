#!/bin/sh
# checksize.sh:  scan the ports collection for "size mismatch" and
# "size unknown" errors by attempting to fetch onto a full filesystem
#
# When called with a parameter that is the name of a category of
# ports, the script checks that category, then checks the whole
# ports collection, redoing the named category.  When called with
# no parameter, it checks the whole collection.
#
# First do something like:
#
#	dd if=/dev/zero of=/usr/ports/mfs.img bs=1k count=512
#	mdconfig -a -t vnode -f /usr/ports/mfs.img -u 1
#	newfs /dev/md1
#	mount /dev/md1 /mnt
#
# (for RELENG_4 use vnconfig instead of mdconfig).  Then run this
# while logging with, for example, the "script" utility and look
# for "size mismatch" (indicating the server has a distfile with a
# different size than what is listed in the distinfo file) and "size
# unknown" (indicating that the server does not report file sizes)
# errors in the output.  Pipe the output through:
#
# 	grep -w size | grep -1 -E "unknown|mismatch"
#
# By keeping the filesystem full, we avoid fetching entire distfiles.
# The script attempts to partially download each distfile from all
# master sites.  Contacting all sites is desirable because sometimes
# a site which ostensibly mirrors another may contain corrupt files
# which are intact on the main site (or vice versa).
#
# bugs:
# - assumes ports tree is in /usr/ports/
# - doesn't provide for checking only particular categories or ports
# - support for multiple architectures is inefficient
# - output is messy
# - on my system, the first 20 kB of each distfile are fetched
#   (this can be suppressed by adding FETCH_BEFORE_ARGS=-s to the make options,
#   in which case the word "Unknown" appears by itself on a line
#   where otherwise there would be a "size unknown" error, and "size
#   mismatch" errors are not detected)
# - needs manual setup of /mnt/
#
# placed in the public domain by Trevor Johnson

for category in $1 `grep ^SUBDIR /usr/ports/Makefile | cut -f3 -d\ `; do
	cd /usr/ports/$category
	for port in \
		`grep -wc SIZE */distinfo* | grep -v :0 | cut -f1 -d\/`; do
		cd /usr/ports/$category/$port
		for arc in i386; do
			dd if=/dev/zero of=/mnt/zero
			echo checking $arc size data for $category/$port
			make	DISTDIR=/mnt \
				ARCH=$arc \
				BATCH=yes \
				MACHINE_ARCH=$arc \
				PACKAGE_BUILDING=yes \
				TRYBROKEN=yes checksum
			rm -rf /mnt/*
		done
	done
done
