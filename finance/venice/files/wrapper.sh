#!/bin/sh
#
# Under a BSDL license. Copyright by Mario S F Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

export JAVA_VERSION

# java
JAVAVM="%%JAVAVM%%"
JAVA_VERSION="%%JAVA_VERSION%%"
JAVAJARDIR="%%JAVAJARDIR%%"
JARFILE="%%JARFILE%%"

exec ${JAVAVM} \
	-jar ${JAVAJARDIR}/${JARFILE} \
	"${@}"
