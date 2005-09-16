#!/bin/sh
cd %%DUKEDIR%%

if [ ! -d %%DUKEDIR%% ] || [ ! -w %%DUKEDIR%% ]
then
	echo You do not have permission to write to %%DUKEDIR%%.
	exit
fi

if [ ! -f DUKE3D.GRP ]
then
	echo DUKE3D.GRP is missing
	exit
fi

echo Renamed DUKE3D.GRP to duke3d.grp
mv -f ./DUKE3D.GRP ./duke3d.grp
