#!/bin/sh

PREFIX="%%PREFIX%%"
LOCALBASE="%%LOCALBASE%%"
PROGRAM="${0}"
SATELLITE=AGSatellite

if [ ! -d ${HOME}/.agsatellite ] || [ ! -h ${HOME}/.agsatellite/${SATELLITE} ]
then
	${LOCALBASE}/bin/${SATELLITE} -createdironly
fi

	cd ${HOME}/.agsatellite &&
	echo Running Audio Galaxy Browser under ${HOME}/.agsatellite &&
	echo Use this directory as the Satellite Directory in the Settings Tab &&
	exec ${PREFIX}/bin/${PROGRAM##*/}-real ${*}
