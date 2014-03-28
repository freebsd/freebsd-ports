# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-input

COMMENT=	Input plugin for Mupen64

BROKEN=		Fails to build
USE_SDL=	sdl

FIXFILES=	#

PLUGIN_NAME=	mupen64_input

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS_SLAVE=	GTK2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
