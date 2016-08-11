# Created by: mm@FreeBSD.org
# $FreeBSD$

PORTREVISION=	1

# the SVG and PANGO plugins need X11
OPTIONS_EXCLUDE=	X11 SVG PANGO
PORTSCOUT=	ignore:1
# workaround until bsd.port.mk code can grok the disabling of the X11 option
WITHOUT_X11=yes

MASTERDIR=	${.CURDIR}/../ImageMagick7

.include        "${MASTERDIR}/Makefile"
