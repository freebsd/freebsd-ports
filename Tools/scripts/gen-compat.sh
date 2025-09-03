#!/bin/sh

set -eu
set -o pipefail

prog=${0##*/}

usage()
{
	echo "Usage $prog <version> <arch> <filelist>" >&2
	exit 1
}

if [ $# -ne 3 ]; then
	usage
fi

version=${1}
arch=${2}
filelist=${3}

if [ ! -f ${filelist} ]; then
	echo "filelist if not a file" >&2
	usage
fi

case $arch in
aarch64 | amd64 | powerpc64)
	sets="base lib32" ;;
*)
	sets="base" ;;
esac
tarch=${arch}
if [ $tarch = "arm64" ]; then
	tarch="aarch64"
fi
if [ $tarch = "aarch64" ]; then
	arch="arm64"
fi
if [ $tarch = "powerpc64" ]  || [ $tarch = "powerpc64le" ]; then
	arch="powerpc"
fi
if [ $tarch = "riscv64" ]; then
	arch="riscv"
fi

flist=""
while read l ; do
	flist="$flist */$l"
done <$filelist

tmpdir=$(mktemp -d)
trap "rm -rf $tmpdir" 0 1 2 3 15
mkdir -p ${tmpdir}/base
set -o noglob
for s in $sets; do
	echo "Fetching $s for ${version}"
	extract_list="$flist"
	if [ $s = "base" ]; then
		extract_list="${extract_list} */sys/param.h"
	fi
	fetch -o - https://download.freebsd.org/releases/${arch}/${tarch}/${version}-RELEASE/${s}.txz | tar -C ${tmpdir}/base -x -f - $extract_list
done
set +o noglob
fbsd_version=$(awk '/#define __FreeBSD_version/ { print $3 }' ${tmpdir}/base/usr/include/sys/param.h)
maj_version=${version%%.*}
date=$(date "+%Y%m%d")
compatdir="compat${maj_version}x-${tarch}-${version}.${fbsd_version}.${date}"
mkdir -p ${tmpdir}/${compatdir}/lib
case $sets in
*lib32*)
	mkdir -p ${tmpdir}/${compatdir}/lib32
	find ${tmpdir}/base/usr/lib32/ -name "*.so.*" -exec mv -v {} ${tmpdir}/${compatdir}/lib32/ \;
	;;
esac
find ${tmpdir}/base -name "*.so.*" -exec mv -v {} ${tmpdir}/${compatdir}/lib/ \;
tar -cvJf ${compatdir}.tar.xz -C ${tmpdir} ${compatdir}
