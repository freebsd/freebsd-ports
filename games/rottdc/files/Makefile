# Makefile wrapper for building both full and shareware versions.
#
# $FreeBSD$
#

all: rott rott-sw
	$(MAKE) -C rott
	$(MAKE) -C rott-sw

rott-sw:
	cp -r rott rott-sw
	sed -i '' -Ee 's|(SHAREWARE) *0|\1 1|' rott-sw/develop.h
	sed -i '' -Ee 's|(SUPERROTT) *1|\1 1|' rott/develop.h
