#!/bin/sh
cd %%DUKEDIR%%

if [ ! -d %%DUKEDIR%% ] || [ ! -w %%DUKEDIR%% ]
then
	echo You do not have permission to write to %%DUKEDIR%%.
	exit
fi

if [ ! -d testdata ]
then
	echo testdata directory is missing
	exit
fi

if [ ! -f testdata/defs.con ] || [ ! -f testdata/game.con ] ||  [ ! -f testdata/user.con ]
then
	echo At least one resource file in testdata is missing
	exit
fi

if [ -f DEFS.CON ]
then                                                             
        echo Backing up original DEFS.CON to DEFS.BAK
	cp DEFS.CON DEFS.BAK
fi

if [ -f GAME.CON ]
then                                                             
        echo Backing up original GAME.CON to GAME.BAK
	cp GAME.CON GAME.BAK
fi

if [ -f USER.CON ]
then                                                             
        echo Backing up original USER.CON to USER.BAK
	cp USER.CON USER.BAK
fi

cp -f testdata/defs.con ./DEFS.CON
cp -f testdata/game.con ./GAME.CON
cp -f testdata/user.con ./USER.CON
