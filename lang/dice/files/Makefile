# Makefile for dice
# Created by Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

DCCOPTS=	-3.0 -//
DINCLUDE=	`pwd`/include/

all:
	cd suplib && ${MAKE} && ${MAKE} install
	cd src && ${MAKE} && ${MAKE} install
	
install:
