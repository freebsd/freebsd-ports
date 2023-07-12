#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

## args

VERSION="$1"

## checks

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

# substitute version
sed -i '' -E "s/(VERSION=[\t ]*)[0-9.]+/\1${VERSION}/" Makefile.new

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
}' < Makefile.new > Makefile.new1 &&
/bin/mv Makefile.new1 Makefile.new

# update distinfo
make -f Makefile.new makesum

# replace the placeholder
while IFS= read -r line; do
	if [ "$line" = "#@@@PLACEHOLDER@@@" ]; then
		make -f Makefile.new cargo-crates | grep -v '^='
	else
		echo "$line"
	fi
done < Makefile.new > Makefile.new1 &&
mv Makefile.new1 Makefile.new

# move Makefile.new
mv Makefile.new Makefile

# update distinfo
make clean makesum
