#!/bin/sh
#
# $FreeBSD$
#

JAVALIBDIR=%%JAVALIBDIR%%

echo -n .
find -s ${JAVALIBDIR} -name '*.jar' | while read jar ; do
	echo -n ":${jar}"
done
