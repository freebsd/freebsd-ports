# New ports collection makefile for:	xmms-nebulus
# Date created:				3 Oct 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-nebulus
PORTVERSION=	0.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://nebulus.tuxfamily.org/

MAINTAINER=	dyeske@yahoo.com

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/SDL.h|SDL11/SDL.h|g; \
	s|SDL/SDL_thread.h|SDL11/SDL_thread.h|g' \
		 ${WRKSRC}/src/nebulus.c

.include <bsd.port.mk>
