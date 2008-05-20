# New ports collection makefile for:	mupen64plus-gln64
# Date created:		2008-05-16
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-gln64

COMMENT=	The glN64 graphics plugin for Mupen64plus

USE_GL=		yes
USE_SDL=	sdl

FIXFILES=	glN64/DepthBuffer.cpp

PLUGIN_NAME=	glN64

MASTERDIR=	${.CURDIR}/../mupen64plus-base

OPTIONS=	#

.include "${MASTERDIR}/Makefile"
