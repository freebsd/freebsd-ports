#!/bin/sh
# ascii-setup ${FILESDIR} ${DISTDIR} [BATCH]
if [ "$3" = "BATCH" ] ; then
        BATCH=yes
fi

if [ "${BATCH}" = "yes" ]; then
        CHOICE=default
else
	echo "Setup for ASCII pTeX"
	echo "Select kanji code on ASCII pTeX."
	echo "1. EUC (default)"
	echo "2. SJIS"
	read CHOICE
fi
case ${CHOICE} in
	2)
	echo "SJIS" ;
	echo 
	KANJI="SJIS"
	;;
	*)
	echo "EUC"
	echo 
	KANJI="EUC"
	;;
esac

if [ "$BATCH" = "yes" ]; then
        CHOICE=default
else
	echo "Select memory model of ASCII pTeX."
	echo "1. Big (default)"
	echo "2. Small"
	read CHOICE
fi
case ${CHOICE} in
	2)
	echo "Small" ;
	echo 
	MEMORY="small"
	;;
	*)
	echo "Big"
	echo 
	MEMORY="big"
	;;
esac

cd jtex1.7

if  [ "${KANJI}" = "EUC" ] ; then
	./EUCsetup
fi

cd ptex/ptex

if  [ "${KANJI}" = "EUC" ] && [ "${MEMORY}" = "big" ] ; then 
	cp texdir/pctex.ch.euc.big texdir/pctex.ch
elif  [ "${KANJI}" = "EUC" ] && [ "${MEMORY}" = "small" ] ; then 
	cp texdir/pctex.ch.euc.small texdir/pctex.ch
elif  [ "${KANJI}" = "SJIS" ] && [ "${MEMORY}" = "big" ] ; then 
	cp texdir/pctex.ch.sj.big texdir/pctex.ch
elif  [ "${KANJI}" = "SJIS" ] && [ "${MEMORY}" = "small" ] ; then
	cp texdir/pctex.ch.sj.small texdir/pctex.ch
fi

if  [ "${KANJI}" = "EUC" ] ; then
mv site.h site.h.orig
cat site.h.orig | sed -e "s/#define	SJIS/#undef	SJIS/g" | \
	sed -e "s/#undef	EUC/#define	EUC/g" > site.h
fi

cp $2/pTeX-JIS-patch .
patch < $1/pTeX-JIS-patch.of.patch
patch -p < pTeX-JIS-patch
mv site.h site.h.orig
cat site.h.orig | sed -e "s/#undef	JIS/#define	JIS/g" > site.h

if [ ! -d /usr/local/bin ] ; \
	then mkdir /usr/local/bin ; fi
if [ ! -d /usr/local/share ] ; \
	then mkdir /usr/local/share ; fi
if [ ! -d /usr/local/share/tex ] ; \
	then mkdir /usr/local/share/tex ; fi
if [ ! -d /usr/local/share/tex/fonts ] ; \
	then mkdir /usr/local/share/tex/fonts ; fi
if [ ! -d /usr/local/share/tex/jfonts ] ; \
	then mkdir /usr/local/share/tex/jfonts ; fi
if [ ! -d /usr/local/share/tex/jfonts/mincho ] ; \
	then mkdir /usr/local/share/tex/jfonts/jfms ; fi
if [ ! -d /usr/local/share/tex/ainputs ] ; \
	then mkdir /usr/local/share/tex/ainputs ; fi
if [ ! -d /usr/local/share/tex/aformats ] ; \
	then mkdir /usr/local/share/tex/aformats ; fi
if [ ! -d /usr/local/share/tex/apool ] ; \
	then mkdir /usr/local/share/tex/apool ; fi
if [ ! -d /usr/local/share/tex/inputs ] ; \
	then mkdir /usr/local/share/tex/inputs ; fi 
