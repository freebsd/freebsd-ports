#!/bin/sh

PREFIX="%%PREFIX%%"
PROGRAM="${0}"
DATADIR="%%DATADIR%%"
HOME_DIR=${HOME}/.iip
NODE_REF=node.ref

if [ ! -d ${HOME_DIR} ]
then
	mkdir -p ${HOME_DIR}
fi

if [ ! -f ${HOME_DIR}/${NODE_REF} ]
then
	cp -f ${PREFIX}/${DATADIR}/${NODE_REF} \
		${HOME_DIR}
fi

cd ${HOME_DIR} &&
	exec ${PREFIX}/sbin/${PROGRAM##*/}-real "${@}"
