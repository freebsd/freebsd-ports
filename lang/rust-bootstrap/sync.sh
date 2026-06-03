#!/bin/sh
# Requires: pkg install yq
# Upload Rust bootstraps available on pkg.FreeBSD.org to your
# ~/public_distfiles on freefall for the next lang/rust update.
# Change ABI below to select from which build to fetch the packages
# from.
set -xeu
: "${PORTSDIR=/usr/ports}"
: "${DATADIR=/tmp/rust-bootstrap}"

fetch -qo /tmp/channel-rust-stable.toml https://dev-static.rust-lang.org/dist/channel-rust-stable.toml
version=$(</tmp/channel-rust-stable.toml tomlq -r '.pkg.rustc.version | split(" ")[0]')
new_commit=$(</tmp/channel-rust-stable.toml tomlq -r '.pkg.rustc.git_commit_hash')
rm /tmp/channel-rust-stable.toml

fetch -qo /tmp/stage0 https://raw.githubusercontent.com/rust-lang/rust/${new_commit}/src/stage0
date=$(awk -F "=" /^compiler_date/'{print $2}' /tmp/stage0)

version=$(make -C "${PORTSDIR}/lang/rust" -V PORTVERSION)

export ABI=FreeBSD:13:amd64
export INSTALL_AS_USER=1
export PKG_DBDIR="${DATADIR}/pkgdb"
pkg update -f -r FreeBSD-ports
pkg fetch -r FreeBSD-ports -o "${DATADIR}" -yg "*-rust-bootstrap-${version}*"

find "${DATADIR}/All" -name "*rust-bootstrap-${version}*.*" \
	-execdir tar -xvf {} \;

dir="/home/rust/public_distfiles/${date}"
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
tar -cf- . | ssh freefall.freebsd.org "mkdir -m 775 -p \"${dir}\" && tar -C \"${dir}\" -xvf-"
cd /
rm -r "${DATADIR}"
