#!/bin/sh
# $FreeBSD$
CLASSPATH=${CLASSPATH}:robocode.jar:tools.jar:.
export CLASSPATH

cd %%PREFIX%%/share/java/robocode
exec %%JAVAVM%% robocode.Robocode "$@"
