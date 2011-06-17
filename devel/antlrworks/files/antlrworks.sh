#! /bin/sh
#
# $FreeBSD$

JAVA_VERSION="%%JAVA_VERSION%%" "%%LOCALBASE%%/bin/java" -classpath "%%JAVAJARDIR%%/%%PORTNAME%%.jar" org.antlr.works.IDE "$@"
 
