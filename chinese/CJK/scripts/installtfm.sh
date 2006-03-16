#!/bin/sh

PATH=/bin:/usr/bin:${LOCALBASE}/bin; export PATH

TFMNAME="$1"
TTFNAME="$2"
SFD="$3"

TEXMFMAIN=`kpsexpand '$TEXMFMAIN'`
SLANT=0.3
INSTALL_DIR="/usr/bin/install -d -m 0755 -o root -g wheel"

CJKTTFDIR=${TEXMFMAIN}/fonts/truetype/CJK
TFMDIR=${TEXMFMAIN}/fonts/tfm/CJK/${TFMNAME}

#Generate and install TFM files
${INSTALL_DIR} ${TFMDIR}

(
	cd ${TFMDIR}
	ttf2tfm ${CJKTTFDIR}/${TTFNAME} -q -P 3 -E 1 ${TFMNAME}@${TEXMFMAIN}/ttf2pk/${SFD}@
	ttf2tfm ${CJKTTFDIR}/${TTFNAME} -q -P 3 -E 1 -s ${SLANT} ${TFMNAME}sl@${TEXMFMAIN}/ttf2pk/${SFD}@
)
