#!/bin/sh
CLASSDIR=%%PREFIX%%/share/java/classes
exec javavm \
    -classpath ${CLASSDIR}/xml-apis.jar \
    -jar ${CLASSDIR}/xalan.jar "$@"
