#!/bin/sh

if [ X$1 = X ]
then
	exit 0
fi

if ! cd $1
then
	exit 1
fi

rm makefile

for FILE in *
do
	tr -d '\r' <${FILE} >${FILE}.NEW
	mv ${FILE}.NEW ${FILE}
done

