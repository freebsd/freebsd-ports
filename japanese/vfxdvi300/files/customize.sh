#!/bin/sh
# usage sh customize.sh ${RESOLUTION} [BATCH]

DEFAULT_FONT_PATH=.:/usr/local/lib/fonts/pk$1:/usr/local/share/tex/jfonts/jfms:/usr/local/lib/texmf/fonts/public/ptex/tfm:/usr/local/share/texmf/fonts/tfm/ptex

DONE=no
if [ $# = 2 ] ; then
	DONE=yes
fi

echo "Check directory for pkfonts (resolution:$1) and ASCII jTeX's tfm files."
echo
echo "Default is .:/usr/local/lib/fonts/pk$1:/usr/local/share/tex/jfonts/jfms:\\"
echo "		:/usr/local/lib/texmf/fonts/public/ptex/tfm:/usr/local/share/texmf/fonts/tfm/ptex"
echo "If you use jlatex of ports collection, it should be OK."
echo

while [ "$DONE" != "yes" ]
do
	echo "Is it OK (y/n)[y]?"
	read ans
	case x"${ans}" in
	xN*|xn*)
		echo "Type DEFAULT_FONT_PATH:"
		read DEFAULT_FONT_PATH
		echo
		echo "DEFAULT_FONT_PATH=${DEFAULT_FONT_PATH}"
	;;
	*)
		DONE=yes
	;;
	esac
done
echo "DEFAULT_FONT_PATH=${DEFAULT_FONT_PATH}"

CHANGE=`echo ${DEFAULT_FONT_PATH} | sed -e 's/\//\\\\\//g'`

cp Imakefile Imakefile.tmp
cat Imakefile.tmp \
| sed -e "s/DEFAULT_FONT_SIZES=FontSizes300/DEFAULT_FONT_SIZES=FontSizes$1/g"\
| sed -e "s/-DBDPI=300/-DBDPI=$1/g"\
| sed -e "s/DEFAULT_FONT_PATH=CHANGE/DEFAULT_FONT_PATH=${CHANGE}/g" \
> Imakefile
rm Imakefile.tmp

if [ $1 = "360" ] || [ $1 = "400" ] || [ $1 = "600" ] ; then
	echo "Default shrink level is set to 5."
cp Imakefile Imakefile.tmp
cat Imakefile.tmp \
| sed -e 's/DEFAULT_SHRINK=\\\"4\\\"/DEFAULT_SHRINK=\\\"5\\\"/g' \
> Imakefile
rm Imakefile.tmp
fi

if [ $# = 1 ] ; then
echo
echo "Do you like to customize Imakefile again by yourself (y/n)[no]?"
read ans
case x"${ans}" in
	xY*|xy*)
	if [ ${EDITOR} ] ; then
		${EDITOR} Imakefile
	else
		vi Imakefile
	fi
	;;
esac
fi
