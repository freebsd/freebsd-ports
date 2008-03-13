# New ports collection makefile for:	mupen64-gln64
# Date created:		11.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.4.1
PORTREVISION=	6
PKGNAMESUFFIX=	-gln64

COMMENT=	The glN64 graphics plugin for Mupen64

USE_GL=		yes
USE_SDL=	sdl

FIXFILES=	glN64/DepthBuffer.cpp glN64/glATI.h

PLUGIN_NAME=	glN64

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS=	#

.include "${MASTERDIR}/Makefile"
