# $FreeBSD$

PORTVERSION=	1.3
PORTREVISION=	3
PKGNAMESUFFIX=	-sdlaudio

COMMENT=	JttL's SDL audio plugin for Mupen64

BROKEN=		Fails to build
USE_SDL=	sdl

FIXFILES=	#

PLUGIN_NAME=	jttl_audio

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS_SLAVE=	GTK2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
