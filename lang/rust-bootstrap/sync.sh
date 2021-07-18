#!/bin/sh
# Upload Rust bootstraps available on pkg.FreeBSD.org to your
# ~/public_distfiles on freefall for the next lang/rust update.
# Change ABI below to select from which build to fetch the packages
# from.
set -xeu
: "${PORTSDIR=/usr/ports}"
: "${DATADIR=/tmp/rust-bootstrap}"

version=$(make -C "${PORTSDIR}/lang/rust" -V PORTVERSION)
date=$(fetch -qo- https://static.rust-lang.org/dist/channel-rust-stable-date.txt)

export ABI=FreeBSD:13:amd64
export INSTALL_AS_USER=1
export PKG_DBDIR="${DATADIR}/pkgdb"
pkg update -f -r FreeBSD
pkg fetch -r FreeBSD -o "${DATADIR}" -yg "*-rust-bootstrap-${version}*"

find "${DATADIR}/All" -name "*rust-bootstrap-${version}*.txz" \
	-execdir tar -xvf {} \;

dir="public_distfiles/rust/${date}"
cd "${DATADIR}/All/usr/local/rust-bootstrap"
mkdir -p tmp
for arch in $(ls); do
	if [ "$arch" == "amd64" ]; then
		find $arch -name '*.tar.xz' -exec mv {} tmp \;
	else
		find $arch -name '*.tar.xz' -and -not -name '*x86_64*' -exec mv {} tmp \;
	fi
done
cd tmp
tar -cf- . | ssh freefall.freebsd.org "mkdir -p \"${dir}\" && tar -C \"${dir}\" -xvf-"
cd /
rm -r "${DATADIR}"
