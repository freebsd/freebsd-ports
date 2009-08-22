# New ports collection makefile for:   lgeneral
# Date created:                27 Aug 2002
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	lgeneral
PORTVERSION=	1.1.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-engine/1.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A turn-based strategy engine inspired by Panzer General

USE_SDL=	sdl

.ifndef (WITHOUT_SOUND)
USE_SDL=	mixer
.else
CONFIGURE_ARGS+=--disable-sound
.endif

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
