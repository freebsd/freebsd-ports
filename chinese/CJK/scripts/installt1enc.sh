#!/bin/sh
#
# Origin By Edward G.J. Lee 2001.11.25
# http://www.study-area.org/tips/latex/pdftex.html
# This code is Public Domain.
#
# Modified by intron@intron.ac, 2006.2.22
#

PATH=/bin:/usr/bin:${LOCALBASE}/bin; export PATH

FONTNAME="$1"
TTFFILE="$2"
ENCODING="$3"

if [ "$ENCODING" = "GB" ]; then
	MAPFILE=cugb.map
	PLANENUMSTART=1
	PLANENUM=35
elif [ "$ENCODING" = "GBK" ]; then
	MAPFILE=cugbk.map
	PLANENUMSTART=1
	PLANENUM=94
elif [ "$ENCODING" = "Bg5" ]; then
	MAPFILE=cubig5.map
	PLANENUMSTART=1
	PLANENUM=55
elif [ "$ENCODING" = "Bg5+" ]; then
	MAPFILE=cubg5plus.map
	PLANENUMSTART=1
	PLANENUM=94
elif [ "$ENCODING" = "UTF8" ]; then
	# No map file for ttf2pt1
	PLANENUMSTART=0
	PLANENUM=255
else
	echo "Unknown encoding '$ENCODING' !"
	exit 1
fi


TEXMFMAIN=`kpsexpand '$TEXMFMAIN'`

MAPFILE=${LOCALBASE}/share/ttf2pt1/maps/${MAPFILE}

CJKTTFDIR=${TEXMFMAIN}/fonts/truetype/CJK
ENCDIR=${TEXMFMAIN}/fonts/enc/CJK/${FONTNAME}
PFBDIR=${TEXMFMAIN}/fonts/type1/CJK/${FONTNAME}

#This is a hack.
UPDMAPCFG=`kpsewhich -format 'web2c files' updmap.cfg`
TEXMFCNF=`kpsewhich -format 'web2c files' texmf.cnf`

SLANT="0.3"

INSTALL_DIR="install -d -m 0755 -o root -g wheel"
INSTALL="install -m 0444 -o root -g wheel"

n=${PLANENUMSTART}

#Create directories
${INSTALL_DIR} ${ENCDIR}
${INSTALL_DIR} ${PFBDIR}

echo "Generating Type 1 subfonts $FONTNAME from $TTFFILE [$ENCODING planes: $n-$PLANENUM]:"

while [ $n -le $PLANENUM ]
do
  echo -n "[$n]"
  if [ "$ENCODING" = "UTF8" ]; then
    # Hexadecimal for Unicode
    m=`printf %02x $n`
  else
    # Decimal
    m=`printf %02d $n`
  fi
  SUBFONTNAME=t1${FONTNAME}${m}
  SUBFONTNAMESLANT=t1${FONTNAME}sl${m}
  
  # Generate *.pfb *.enc
  if [ "$ENCODING" = "UTF8" ]; then
    ttf2pt1 -b -GaEF -pft -Ohub -W0 -l plane+pid=3,eid=1,0x$m "${CJKTTFDIR}/$TTFFILE" ${SUBFONTNAME}
  else
    ttf2pt1 -b -GaEF -pft -Ohub -W0 -L $MAPFILE+$m "${CJKTTFDIR}/$TTFFILE" ${SUBFONTNAME}
  fi

  # Generate mapping files for updmap & PDFTeX
  fontfullname=`head -n 1 ${SUBFONTNAME}.enc | sed -e 's,^/\(.*\)Encoding.*$,\1,'`
  echo -n "${SUBFONTNAME} ${fontfullname} <${SUBFONTNAME}.pfb
${SUBFONTNAMESLANT} ${fontfullname} \" ${SLANT} SlantFont \" <${SUBFONTNAME}.pfb
" >> CJK-type1.map

  echo -n "${FONTNAME}${m} ${fontfullname} <${SUBFONTNAME}.enc <${TTFFILE}
" >> CJK-pdftex.map

  ${INSTALL} ${SUBFONTNAME}.pfb ${PFBDIR}
  ${INSTALL} ${SUBFONTNAME}.enc ${ENCDIR}

  n=`expr $n + 1`
done

echo
