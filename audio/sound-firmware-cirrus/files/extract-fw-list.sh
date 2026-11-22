#!/bin/sh
#
# Generate the firmware file and link lists of the Makefile from the
# linux-firmware WHENCE file.  Usage:
#	extract-fw-list.sh /path/to/WHENCE chip...
# e.g. extract-fw-list.sh linux-firmware/WHENCE cs35l54
#
# File: lines name real files; Link: lines name symlinks, with a target
# relative to the link directory.  Real files that links point to are
# added to the file list.

set -eu

whence=$1
shift

for chip in "$@"; do
	awk -v chip="${chip}" '
	$1 == "File:" && $2 ~ "^cirrus/" chip "-" {
		files[$2] = 1
	}
	$1 == "Link:" && $2 ~ "^cirrus/" chip "-" {
		links[$2] = $4
		# Resolve the target relative to the link directory.
		target = "cirrus/" $4
		files[target] = 1
	}
	END {
		# A link target may itself be a link: keep only real files.
		for (f in files)
			if (!(f in links))
				print "F " f
		for (l in links)
			print "L " l " " links[l]
	}' "${whence}" | sort | awk -v chip="${chip}" '
	$1 == "F" { f[nf++] = $2 }
	$1 == "L" { l[nl++] = $2 ":" $3 }
	END {
		printf "FWFILES_%s=\t", chip
		for (i = 0; i < nf; i++)
			printf "%s\\\n\t%s", (i ? " " : ""), f[i]
		printf "\n\nFWLINKS_%s=\t", chip
		for (i = 0; i < nl; i++)
			printf "%s\\\n\t%s", (i ? " " : ""), l[i]
		printf "\n"
	}'
done
