#!/bin/sh
# $FreeBSD: /tmp/pcvs/ports/editors/jedit-devel/files/Attic/jedit.sh,v 1.1 2004-06-03 02:35:30 ijliao Exp $

# Java heap size, in megabytes
JAVA_HEAP_SIZE=32

exec %%LOCALBASE%%/bin/javavm -mx${JAVA_HEAP_SIZE}m ${JEDIT} -jar \
	"%%PREFIX%%/share/java/jedit/jedit.jar" "$@"
