#!/bin/sh
#
# $FreeBSD$

%%LOCALBASE%%/bin/java -cp "%%JAVAJARDIR%%/checkstyle.jar:%%JAVAJARDIR%%/checkstyle-optional.jar" com.puppycrawl.tools.checkstyle.Main "$@"
