#!/bin/sh

PREFIX="%%PREFIX%%"
PROGRAM="${0}"

exec ${PREFIX}/${PROGRAM##*/} "${@}" &
