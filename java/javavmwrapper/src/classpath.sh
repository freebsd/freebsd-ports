#!/bin/sh
#
# $FreeBSD$
#

JAVAJARDIR=%%JAVAJARDIR%%

echo -n .
find -s ${JAVAJARDIR} -name '*.jar' | while read jar ; do
	echo -n ":${jar}"
done
