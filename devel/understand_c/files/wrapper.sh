#!/bin/sh

PREFIX="%%PREFIX%%"
PROGRAM="${0}"

if [ ${#} -gt 1 ]
then
	shift
fi

exec ${PREFIX}/${PROGRAM##*/} ${*} &
