#!/bin/sh
# ntt-setup ${FILESDIR} ${DISTDIR} [BATCH]
if [ "$3" = "BATCH" ] ; then
        BATCH=yes
	echo Batch mode
fi
cd jtex-1.52
sh configure
cp $1/ntt-EUC.patch $1/ntt-SJIS.patch . 
if [ "$BATCH" = "yes" ]; then
        CHOICE=both
else
	echo "Setup for NTT jTeX"
	echo "Select kanji code on NTT jTeX."
	echo "1. EUC(default)."
	echo "2. JIS."
	echo "3. SJIS." 
read CHOICE 
fi
case ${CHOICE} in
	2)
	 echo "Use JIS code for NTT jTeX"
	 echo
	 patch < ntt-EUC.patch 
	;;
	3)
	 echo "Use SJIS code for NTT jTeX" ;
	 patch < ntt-SJIS.patch
	;;
	*) 
	 echo "Use EUC code for NTT jTeX" 
	 echo
	 patch < ntt-EUC.patch 
;; 
esac 

if [ ! -d /usr/local/share/tex ] ; \
	then mkdir /usr/local/share/tex ; fi
if [ ! -d /usr/local/share/tex/fonts ] ; \
	then mkdir /usr/local/share/tex/fonts ; fi
if [ ! -d /usr/local/share/tex/jfonts ] ; \
	then mkdir /usr/local/share/tex/jfonts ; fi
if [ ! -d /usr/local/share/tex/jfonts/mincho ] ; \
	then mkdir /usr/local/share/tex/jfonts/mincho ; fi
if [ ! -d /usr/local/share/tex/jfonts/gothic ] ; \
	then mkdir /usr/local/share/tex/jfonts/gothic ; fi
if [ ! -d /usr/local/share/tex/jfonts/jfms ] ; \
	then mkdir /usr/local/share/tex/jfonts/jfms ; fi
if [ ! -d /usr/local/share/tex/ninputs ] ; \
	then mkdir /usr/local/share/tex/ninputs ; fi
if [ ! -d /usr/local/share/tex/nformats ] ; \
	then mkdir /usr/local/share/tex/nformats ; fi
if [ ! -d /usr/local/share/tex/npool ] ; \
	then mkdir /usr/local/share/tex/npool ; fi
if [ ! -d /usr/local/share/tex/inputs ] ; \
	then mkdir /usr/local/share/tex/inputs ; fi 

cp JTeXfonts/dnpfonts/mincho/tfm/* /usr/local/share/tex/jfonts/mincho/
cp JTeXfonts/dnpfonts/gothic/tfm/* /usr/local/share/tex/jfonts/gothic/
cp JLaTeX/sty/* /usr/local/share/tex/ninputs/
cp ../jtex1.7/macros/* /usr/local/share/tex/inputs

cd /usr/local/share/tex/ 
	  tar xzf $2/tfm-files.tar.Z ; \
	  mv tfm-files/min*  jfonts/jfms/; \
	  mv tfm-files/nmin*  jfonts/jfms/; \
	  mv tfm-files/goth*  jfonts/jfms/; \
	  mv tfm-files/ngoth*  jfonts/jfms/; \
	  mv tfm-files/* fonts/ ; \
	  rmdir tfm-files ; \
	  cd fonts ; \
	  tar xzf  $1/tfm-add.tar.gz ; \
