#!/bin/sh
MDDIR=%%MDDIR%%

for j in $MDDIR/*.jar
do
	cp=$cp:$j
done

exec %%PREFIX%%/bin/javavm -cp ${cp#:} Moneydance
