#!/bin/sh
[ -x /usr/local/uox3/uox3 ] && \
	cd /usr/local/uox3 && \
	/usr/local/uox3/uox3 > /usr/local/uox3/stdout.log & && \
	echo -n ' uox3'
