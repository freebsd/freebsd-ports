#!/bin/sh
# Convert C++ style sources to C style
# $FreeBSD$

FILES=`${FIND} ${WRKSRC} -name '*.c'`;
for i in ${FILES}; do
    if [ -n "`${GREP} -e '//' $i`" ]; then
	${REINPLACE_CMD} -e 's?//\(.*\)?/*\1 */?' $i;
    fi;
done;
