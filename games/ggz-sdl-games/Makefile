# ex:ts=8
# Ports collection makefile for:	ggz-sdl-games
# Date created:			Nov 7, 2005
# Whom:				yinjieh
#
# $FreeBSD$
#

PORTNAME=	ggz-sdl-games
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - SDL-based games

USE_GL=		gl
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/geekgame/module.dsc ${PREFIX}/share/ggz/geekgame.dsc
	${INSTALL_DATA} ${WRKSRC}/ttt3d/module.dsc ${PREFIX}/share/ggz/ttt3d.dsc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/libggz/bsd.ggz.mk"
.include <bsd.port.post.mk>
