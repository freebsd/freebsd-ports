#! /bin/sh
#
# $FreeBSD$

"%%LOCALBASE%%/bin/java" -classpath "%%JAVAJARDIR%%/antlr.jar" antlr.Tool "$@"
