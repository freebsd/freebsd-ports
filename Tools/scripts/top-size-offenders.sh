#!/bin/sh
#
# This script produces a report like this:  
#
#   Combined size of ports: 510.5 Mb
#   The Top 20 ports by size account for 15.14% of the collection
#   ====================================================================
#    [snipped 15 rows]
#    0.37%   1.87Mb  security/cracklib
#    0.66%   3.38Mb  security/vuxml
#    0.87%   4.42Mb  print/texlive-texmf
#    2.82%  14.41Mb  java/openjdk7
#    6.79%  34.66Mb  java/openjdk8
#   ====================================================================
#   15.14%  77.29Mb
#
# Written by John Marino <marino@FreeBSD.org> one rainy day just because ...
#

TOP=20
DUK="du -kd 1 -t 200k [a-z]*"
DASH="======================================================================="
SCRATCH=/tmp/topX

AWKCMD1='BEGIN { FS="/"; }{ if (NF == 2) { print $0; }}'
AWKCMD2='BEGIN { total=0; } { total = total + $1 } END { print total }'
AWKCMD3='{ pc=100.0*$1/total; mega=$1/1024.0; \
  printf("%5.2f%%  %5.2fMb  %s\n", pc, mega, $2)}'

cd /usr/ports && ${DUK} | awk "${AWKCMD1}" | sort -n | tail -n ${TOP} \
	> ${SCRATCH}

total=$(du -sk /usr/ports/[a-z]* | awk "${AWKCMD2}")
outlaws=$(awk "${AWKCMD2}" ${SCRATCH})
megabytes=$(bc -e "scale = 2; ${total} / 1024" -e quit)
bloat=$(bc -e "scale = 2; ${outlaws} / 1024" -e quit)
PC=$(bc -e "scale = 2; 100 * ${outlaws} / ${total}" -e quit)

printf "Combined size of ports: %1.1f Mb\n" ${megabytes}
printf "The Top %d ports by size account for %1.2f%% of the collection\n" \
	${TOP} ${PC}
echo ${DASH}
awk -v total=${total} "${AWKCMD3}" ${SCRATCH}
echo ${DASH}
printf "%5.2f%%  %5.2fMb\n" ${PC} ${bloat}
rm ${SCRATCH}
