#!/bin/sh

# from color-mate-10.0.1/theme/Makefile
for file in *.xdef; do
	dist=`echo $file| sed 's/xdef$/X/'`
	cat $file ./Xdefaults.cpp \
	 | gcc -E - \
	 | sed  -e '/^#  *[0-9][0-9]*  *.*$$/d' \
		-e 's/ $$//' \
		-e /CM_BG/d \
		-e /CM_FG/d \
		-e /CM_BUTTON_BG/d \
		-e /CM_BUTTON_FG/d \
		-e /CM_BUTTON_SHAPE/d \
		-e /CM_HIGHLIGHT_FG/d \
		-e /CM_CHECK/d \
	 | tail +`wc $file | awk '{print $$1 + 1}'` > $dist
done
