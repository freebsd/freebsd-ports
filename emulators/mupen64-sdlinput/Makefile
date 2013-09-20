# $FreeBSD$

PORTVERSION=	0.0.10
PORTREVISION=	3
PKGNAMESUFFIX=	-sdlinput

COMMENT=	Blight's SDL input plugin for Mupen64

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

FIXFILES=	#

USE_SDL=	sdl

PLUGIN_NAME=	blight_input

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS_SLAVE=	GTK2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
