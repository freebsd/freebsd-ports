#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

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
if ! [ -f Makefile ] || ! [ -f pkg-descr ]; then
	echo "$0 should be run in a port directory" >&2
	exit 1
fi

USE_CRATES_FILE=false
if [ -f Makefile.crates ]; then
	USE_CRATES_FILE=true
elif ! grep -q "CARGO_CRATES=" Makefile; then
	echo "$0 should be run in a Rust-based port directory (no CARGO_CRATES found)" >&2
	exit 1
fi

## helpers

substitute_version() {
	# Use awk so version strings containing '/' (e.g. GitHub tag prefixes)
	# do not break the substitution.
	awk -v ver="$VERSION" '
		/^((PORT|DIST)VERSION=[\t ]*)/ {
			prefix = $0
			sub(/[\t ]*[^\t ]*$/, "", prefix)
			print prefix "\t" ver
			next
		}
		{ print }
	' "$1" > "$1.tmp" && mv "$1.tmp" "$1"
}

reset_portrevision() {
	if grep -q "^PORTREVISION=" Makefile; then
		echo PORTREVISION=0 | portedit merge -i Makefile
	fi
}

update_inline_crates() {
	cp Makefile Makefile.new
	substitute_version Makefile.new

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

	BATCH=yes make makesum

	while IFS= read -r line; do
		if [ "$line" = "#@@@PLACEHOLDER@@@" ]; then
			BATCH=yes make cargo-crates | grep -v '^='
		else
			echo "$line"
		fi
	done < Makefile > Makefile.new &&
	mv Makefile.new Makefile
}

update_crates_file() {
	# Keep the include target valid while we fetch the source distfile.
	: > Makefile.crates

	substitute_version Makefile

	BATCH=yes make makesum

	BATCH=yes make cargo-crates | grep -v '^=' > Makefile.crates
}

## MAIN

reset_portrevision

# Make sure a crates-file include target is parseable before we ask make to
# clean up stale work from a previous version.
if $USE_CRATES_FILE; then
	: > Makefile.crates
fi

# Start from a clean work directory so stale extractions do not confuse
# cargo-crates after the version bump.
BATCH=yes make clean || true

if $USE_CRATES_FILE; then
	update_crates_file
else
	update_inline_crates
fi

# clean
BATCH=yes make clean

# update distinfo with the real crate list
BATCH=yes make makesum
