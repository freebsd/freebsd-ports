#!/bin/sh
# $FreeBSD$
CLASSPATH=${CLASSPATH}:robocode.jar:resources.jar:tools.jar:.
export CLASSPATH

cd %%PREFIX%%/share/java/robocode
exec %%JAVAVM%% robocode.Robocode "$@"
