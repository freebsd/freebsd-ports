#!/bin/sh
# linkselect.sh
rm -f /usr/local/share/tex/aformats/jtex.fmt
rm -f /usr/local/share/tex/aformats/jlatex.fmt
rm -f /usr/local/share/tex/nformats/jtex.fmt
rm -f /usr/local/share/tex/nformats/jlatex.fmt
rm -f /usr/local/bin/jtex
rm -f /usr/local/bin/jlatex
echo "Which jlatex do you like to run by 'jlatex' command?"
echo "1. ASCII pTeX as jlatex"
echo "2. NTT jTeX as jlatex"
echo "3. I like to use ajlatex for ASCII and njlatex for NTT(Default)." 
read CHOICE 
case ${CHOICE} in
	1)
	 echo "Run ASCII jTeX by 'jlatex' command" ;
	 echo
	 ln -s /usr/local/share/tex/aformats/ajtex.fmt /usr/local/share/tex/aformats/jtex.fmt
	 ln -s /usr/local/share/tex/aformats/ajlatex.fmt /usr/local/share/tex/aformats/jlatex.fmt
	 ln -s /usr/local/bin/viratex /usr/local/bin/jtex
	 ln -s /usr/local/bin/viratex /usr/local/bin/jlatex
	;;
	2)
	 echo "Run NTT jTeX by 'jlatex' command" ;
	 echo
	 ln -s /usr/local/share/tex/nformats/njtex.fmt /usr/local/share/tex/nformats/jtex.fmt
	 ln -s /usr/local/share/tex/nformats/njlatex.fmt /usr/local/share/tex/nformats/jlatex.fmt
	 ln -s /usr/local/bin/virjtex /usr/local/bin/jtex
	 ln -s /usr/local/bin/virjtex /usr/local/bin/jlatex
	;;
	*) 
	 echo "Default."  
;; 
esac 
