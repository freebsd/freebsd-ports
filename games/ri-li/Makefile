# New ports collection makefile for:	Ri-li
# Date created:		03 Jul 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	Ri-li
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ri-li

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Drive a toy wood train in many levels - snake-like arcade game

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer

CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` -I${X11BASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' ${WRKSRC}/src/*.cc ${WRKSRC}/src/*.h
	@${REINPLACE_CMD} -e 's|-lSDL |`${SDL_CONFIG} --libs`|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/strcpy.*DefPath/ s|.*|strcpy(DefPath,"${DATADIR}/");|' ${WRKSRC}/src/main.cc

.include <bsd.port.mk>
