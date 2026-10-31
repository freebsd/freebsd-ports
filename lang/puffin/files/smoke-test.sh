#!/bin/sh
# Run smoke.pfn through the interpreter, the Nim AOT compiler and the emit-C
# compiler, and require byte-identical, expected output from all three.
#
#   smoke-test.sh WRKSRC WORKDIR PROGRAM
set -eu

src=$1
work=$2
prog=$3

rm -rf "$work"
mkdir -p "$work"

cat > "$work/expected" <<'EXPECTED'
sha256 f3c2984127dd2db50a555194925ca0d55c3c7b676e889c9406b2e6875a67e29c
sqlite sum 42
ed25519 valid 1
ed25519 tampered 0
zstd puffin
bzip2 puffin
EXPECTED

echo "==> interpreter"
"$src/bin/awktua" --interp --dialect puffin -f "$prog" > "$work/interp.out"

echo "==> nim AOT"
"$src/bin/awktua" --dialect puffin -o "$work/prog.nim" -f "$prog"
nim c -d:release -d:awktuaHostLibressl -d:awktuaHostLibsodium --hints:off --warnings:off \
	--nimcache:"$work/nimcache" \
	-o:"$work/prog-nim" "$work/prog.nim"
"$work/prog-nim" > "$work/nim.out"

echo "==> emit-C"
"$src/tools/bin/puffincc" --dialect=puffin -o "$work/prog-c" "$prog"
"$work/prog-c" > "$work/emitc.out"

rc=0
for backend in interp nim emitc; do
	if ! diff -u "$work/expected" "$work/$backend.out"; then
		echo "smoke test: $backend output differs from expected"
		rc=1
	fi
done
[ $rc -eq 0 ] && echo "smoke test: all three backends agree"
exit $rc
