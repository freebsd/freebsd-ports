#!/bin/sh
# chm.sh

if [ -z "$1" ]; then
    echo "file not specified"
    exit 1;
fi

if [ ! -s "$1" ]; then
    echo "file not exist: $1"
    exit 1;
fi

which="/usr/bin/which"

# get full path or ./ of this command
# then, trace back the symbolic link
prefix=`$which $0`
while [ -h "$prefix" ]; do
  lnk_to=`/bin/ls -l "$prefix" | awk '{print $NF}'`
  if echo $lnk_to | grep "^/" >& /dev/null; then
    prefix=$lnk_to
  else
    prefix=${prefix%/*}/$lnk_to
  fi
done

prefix=${prefix%/*}
chm2html="$prefix/chm2html"
hhc2html="$prefix/hhc2html.pl"

for f in "$chm2html" "$hhc2html"; do
  if [ ! -s "$f" ]; then
    echo "${0##*/}: can not execute program '$f'"
    exit 1
  fi
done

chmtmp="/tmp/chm-$$"
contents="$chmtmp/chm-$$.html"

"$chm2html" < "$1" "$chmtmp"
"$hhc2html" "$chmtmp"/`ls "$chmtmp" | grep '\.hhc$'` > "$contents"

mozilla "$contents"

