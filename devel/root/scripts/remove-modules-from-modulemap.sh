#!/bin/sh

# Script removes module definition blocks in LLVM/Clang .modulemap
# files in-place in the file path stored in the variable MODULEMAP

sp='[[:space:]]'

mdls="" ; i=0
for m in "$@" ; do
  i=$((i+1))
  mdls="$mdls($m)"
  [ $i -ne $# ] && mdls="$mdls|"
done

script="\
/^$sp*(explicit)?$sp*module$sp*\"$mdls\"$sp*\{$sp*\$/ {
  :l
    N
    s/}/}/
    tx
    bl
  :x
    d
}\
"

sed -i '' -E "$script" "$MODULEMAP"
