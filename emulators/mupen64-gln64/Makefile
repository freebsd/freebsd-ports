# $FreeBSD$

PORTNAME=	mupen64
PORTVERSION=	0.4.1
PORTREVISION=	8
PKGNAMESUFFIX=	-gln64

COMMENT=	The glN64 graphics plugin for Mupen64

BROKEN=		Fails to build
USE_GL=		yes
USE_SDL=	sdl

FIXFILES=	glN64/DepthBuffer.cpp glN64/glATI.h

PLUGIN_NAME=	glN64

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS_SLAVE=	GTK2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
