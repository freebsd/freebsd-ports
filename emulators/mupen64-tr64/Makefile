# New ports collection makefile for:	mupen64-tr64
# Date created:		2007-10-09
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	0.7.8
PORTREVISION=	2
PKGNAMESUFFIX=	-tr64

COMMENT=	Tr64 graphics plugin for Mupen64

USE_SDL=	sdl
USE_GL=		yes

FIXFILES=	display.c sdlgl.c

PLUGIN_NAME=	tr64gl

MASTERDIR=	${.CURDIR}/../mupen64-base

OPTIONS=	#

.include "${MASTERDIR}/Makefile"
