#!/bin/sh

if [ -z "$BASEDIR" ] ; then 
	exit 1
else
	cd $BASEDIR || exit 1;
	if [ ! -f dmnew.class ]; then exit 1 ;fi
fi

# Fix our dirs
if [ -d SOUNDS ]   ; then mv SOUNDS Sounds ; fi
if [ -d MONSTERS ] ; then mv MONSTERS Monsters ; fi
if [ -d ITEMS ]    ; then mv ITEMS Items ; fi
if [ -d ICONS ]    ; then mv ICONS Icons ; fi
if [ -d SPELLS ]   ; then mv SPELLS Spells ; fi

find -E . -iregex '.*(gif|png|jpg|wav)' -type f | while read i ; do
        mv "$BASEDIR/$i" "$BASEDIR/`dirname "$i"`"/"`echo \`basename $i\` | tr '[A-Z]' '[a-z]'`"
done


# Fix hero portraits
cd $BASEDIR/Heroes || exit 1;
mv -f pantara.gif Pantara.gif
mv -f sana.gif SANA.GIF
mv -f wishbone.gif WISHBONE.GIF
mv -f seppo.gif SEPPO.GIF
mv -f torg.gif Torg.gif
mv -f nagla.gif NAGLA.GIF
mv -f antman.gif ANTMAN.GIF
mv -f warwick.gif WARWICK.GIF
mv -f bnarl.gif Bnarl.gif
mv -f growlg.gif GROWLG.GIF
mv -f morg.gif MORG.GIF

# Fix the directory delimeter
cd $BASEDIR/Dungeons || exit 1;
sed -e 's/Heroes\\/Heroes\//g' < dungeon.dat > dungeon2.dat
mv dungeon2.dat dungeon.dat
