# New ports collection makefile for:	xmms-jess
# Date created:				3 Feb 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-jess
PORTVERSION=	2.9.1
CATEGORIES=	graphics
MASTER_SITES=	http://arquier.free.fr/
DISTNAME=	JESS-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
GNU_CONFIGURE=	yes
USE_GLIB=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
