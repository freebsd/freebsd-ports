#!/bin/sh
if [ "x${JAVA_CMD}" = "x" ]; then
    JAVA_CMD=%%JAVA_HOME%%/bin/java
fi
if [ "$1" = "help" ]; then
    $0 -\? 
fi
cd %%ORION_HOME%% && \
    ${JAVA_CMD} -jar orion.jar $@ 
