#!/bin/sh
# $FreeBSD$

# Java heap size, in megabytes
JAVA_HEAP_SIZE=32

exec %%LOCALBASE%%/bin/javavm -mx${JAVA_HEAP_SIZE}m ${JEDIT} -jar \
	"%%PREFIX%%/share/java/jedit/jedit.jar" "$@"
