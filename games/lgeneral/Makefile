# New ports collection makefile for:   lgeneral
# Date created:                27 Aug 2002
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	lgeneral
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgeneral

MAINTAINER=	filippo@widestore.net
COMMENT=	A turn-based strategy engine inspired by Panzer General

USE_SDL=	yes

.ifndef (WITHOUT_SOUND)
USE_SDL=	mixer
.else
CONFIGURE_ARGS+=--disable-sound
.endif

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
