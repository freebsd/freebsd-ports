# ex:ts=8
# Ports collection makefile for:	ggz-sdl-games
# Date created:			Nov 7, 2005
# Whom:				yinjieh
#
# $FreeBSD$
#

PORTNAME=	ggz-sdl-games
PORTVERSION=	${GGZ_VERSION}
CATEGORIES=	games

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - SDL-based games

USE_GETOPT_LONG=	yes
USE_GL=		yes
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/geekgame/module.dsc ${PREFIX}/share/ggz/geekgame.dsc
	${INSTALL_DATA} ${WRKSRC}/ttt3d/module.dsc ${PREFIX}/share/ggz/ttt3d.dsc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/libggz/bsd.ggz.mk"
.include <bsd.port.post.mk>
