#!/bin/sh
#

CLASSPATH=${CLASSPATH}:/usr/local/share/java/SETISupport/SETISupport.jar
export CLASSPATH

if [ ! -d ${SETISUPPORT_WRKDIR:=${HOME}/.SETISupport} ]; then
	mkdir ${SETISUPPORT_WRKDIR}
fi
cd ${SETISUPPORT_WRKDIR}
exec /usr/local/bin/javavm SETISupport $@
