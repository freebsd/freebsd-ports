#!/bin/sh
YN=N
cd @PREFIX@/share/hns
( echo "$LANG" | /usr/bin/grep -q '^ja' ) && YN=Y
[ "$1" = "ja" ] && YN=Y
if [ "$YN" = "N" ]; then
    echo -n "Japanese message OK? [y/N]: "
    read YN
    [ -n "$YN" ] || YN=N
fi
[ "$1" = "en" ] && YN=N
if [ "$YN" = "Y" -o "$YN" = "y" ]; then
    exec ./hns-setup.ja
else
    exec ./hns-setup.en
fi
