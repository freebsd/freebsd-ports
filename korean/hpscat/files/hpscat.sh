#!/bin/sh
#
# hpscat fontend for FreeBSD ports
#
# 4 Apr 1997, Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# It enables hpscat to print file without loading font in gs
#

HFONTPATH=%%PREFIX%%/share/fonts/ked-hpscat

options=$*
fileoutput=0

# check if -f option is specified
for i in $*
do
        case $i in
              -f)       fileoutput=1; shift;;
        esac
done

if [ $fileoutput != 1 ]; then
# print font header
  cat $HFONTPATH/Header
  for hfont in Munjo Gotic MunjoBold PCMunjo
  do
   cat $HFONTPATH/$hfont
  done
fi

exec hpscat.bin $options
