# New ports collection makefile for:	xmms-jess
# Date created:				3 Feb 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-jess
PORTVERSION=	2.9.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://arquier.free.fr/
DISTNAME=	JESS-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A XMMS visualization plugin that uses SDL

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
GNU_CONFIGURE=	yes
PLIST_FILES=	lib/xmms/Visualization/libjess.so
USE_GNOME=	glib12
USE_X_PREFIX=	yes

.include <bsd.port.mk>
