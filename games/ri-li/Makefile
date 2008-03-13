# New ports collection makefile for:	ri-li
# Date created:		03 Jul 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	Ri-li
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	ri-li

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Drive a toy wood train in many levels - snake-like arcade game

USE_AUTOTOOLS=	automake:19
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer

CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` -I${X11BASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|-lSDL |`${SDL_CONFIG} --libs`|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/strcpy.*DefPath/ s|.*|strcpy(DefPath,"${DATADIR}/");|' ${WRKSRC}/src/main.cc

.include <bsd.port.mk>
