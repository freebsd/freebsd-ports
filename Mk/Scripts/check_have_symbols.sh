#!/bin/sh

set -eu

# the 3 implementations of readelf we can use have different output, but they all have a similarity
# for the .gnu.version_d section they all have the symbol version in last element of their output
# and have "Name:" or "vda_name": in the 10th position, no other section displayed have this
# it means that if there are no symbols exported then nothing matches this search pattern.

STAGEDIR=$1
shift
ret=0
failed=""
for lib; do
	if ! /usr/bin/readelf -V ${STAGEDIR}$lib  | awk 'BEGIN { ret=1 } $10 == "Name:" || $10 == "vda_name:" { ret=0; exit 0 } END { exit ret }'; then
		ret=1
		failed="${failed} ${lib}"
	fi
done
if [ "$failed" != "" ]; then
	echo "the following libraries are supposed to have symbols versioning but they don't" >&2
	for l in ${failed}; do
		echo "- $l" >&2
	done
fi
exit $ret
