#!/bin/sh

PROGRAM="${0}"
DATADIR="%%DATADIR%%"
DIVX_SKIN_DIR=${DATADIR}/Skins

export DIVX_SKIN_DIR

if [ -f ~/.divxPlayer/DivXPlayer.dbf ]
then
	rm -f ~/.divxPlayer/DivXPlayer.dbf
fi

exec ${PROGRAM}.bin "${@}"
