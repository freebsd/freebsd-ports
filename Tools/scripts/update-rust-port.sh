#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

# CAVEAT: ports with Makefile.crates are not yet supported

## args

VERSION="$1"

## set strict mode

STRICT="set -euo pipefail"
$STRICT

## checks

for dep in portedit rustc; do
	if ! which -s $dep; then
		echo "error: $dep dependency is missing, $0 requires lang/rust and ports-mgmt/portfmt to be installed" >&2
		exit 1
	fi
done
if [ -z "$VERSION" ]; then
	echo "Usage: $0 <new-version>"
	exit 1
fi
if ! [ -f Makefile ] || ! [ -f pkg-descr ] || ! grep -q "CARGO_CRATES=" Makefile; then
	echo "$0 should be run in a Rust-based port directory"
	exit 1
fi

## MAIN

# copy Makefile
cp Makefile Makefile.new

# substitute version tag PORTVERSION or DISTVERSION
sed -i '' -E "s/^(PORT|DIST)(VERSION=[\t ]*)[0-9.-]+/\1\2${VERSION}/" Makefile.new

# reset PORTREVISION if present
if grep -q "PORTREVISION=" Makefile; then
	echo PORTREVISION=0 | portedit merge -i Makefile.new
fi

# replace CARGO_CRATES with a placeholder
/usr/bin/awk '
BEGIN {
	in_cargo_crates = 0
}
/^CARGO_CRATES=.*/ {
	in_cargo_crates = 1
	print "#@@@PLACEHOLDER@@@"
}
/^\t.*/ {
	if (in_cargo_crates) {
		// skip line
	} else {
		print $0
	}
}
!/^CARGO_CRATES=.*|^\t.*/ {
	if (in_cargo_crates) {
		in_cargo_crates = 0
	}
	print $0
}' < Makefile.new > Makefile

# update distinfo
make makesum

# replace the placeholder
while IFS= read -r line; do
	if [ "$line" = "#@@@PLACEHOLDER@@@" ]; then
		make cargo-crates | grep -v '^='
	else
		echo "$line"
	fi
done < Makefile > Makefile.new &&
mv Makefile.new Makefile

# clean
make clean

# update distinfo
make makesum
