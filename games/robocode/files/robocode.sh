#!/bin/sh
# $FreeBSD$

cd %%PREFIX%%/share/java/robocode
exec %%JAVAVM%% -jar robocode.jar "$@"
