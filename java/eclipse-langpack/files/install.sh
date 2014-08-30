#!/bin/sh

WRKDIR=$1; PREFIX=$2

cd ${WRKDIR}
for dir  in `find eclipse -type d | sort`; do
	install -d ${PREFIX}/lib/${dir}
done

for file in `find eclipse -type f | sort`; do
	install ${file} ${PREFIX}/lib/${file}
done
