#!/bin/sh
# $FreeBSD$
CLASSPATH=${CLASSPATH}:%%PREFIX%%/share/java/jedit/swingall.jar:%%PREFIX%%/share/java/jedit/jedit.jar
export CLASSPATH

exec %%LOCALBASE%%/bin/javavm org.gjt.sp.jedit.jEdit "$@"
