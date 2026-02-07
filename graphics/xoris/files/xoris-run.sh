#!/bin/sh

while true
do
	xoris | xmessage -buttons 'Grab,Quit' -nearmouse \
		-xrm '*iconName:xoris output' \
		-title 'xoris output' \
		-geometry 180x65 \
		-file -
	[ $? -eq 102 ] && exit
done
