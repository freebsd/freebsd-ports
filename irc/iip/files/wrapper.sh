#!/bin/sh

PREFIX="%%PREFIX%%"
PROGRAM="${0}"
DATADIR="%%DATADIR%%"
HOME_DIR=${HOME}/.iip
NODE_REF=node.ref
RANDOM_DEVICE=/dev/urandom
SEED_FILE=seed.rnd

if [ ! -d ${HOME_DIR} ]
then
	mkdir -p ${HOME_DIR}
fi

if [ ! -f ${HOME_DIR}/${NODE_REF} ]
then
	rm -f ${HOME_DIR}/${NODE_REF}
	cp -f ${PREFIX}/${DATADIR}/${NODE_REF} \
		${HOME_DIR}
	chmod u+w ${HOME_DIR}/${NODE_REF}
fi

# random seed 
if [ -c "${RANDOM_DEVICE}" -o -L "${RANDOM_DEVICE}" ]; then
	head -c 256 /dev/urandom > ${HOME_DIR}/${SEED_FILE}
fi

cd ${HOME_DIR} &&
	exec ${PREFIX}/sbin/${PROGRAM##*/}-real "${@}"
