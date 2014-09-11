# Created by: yinjieh
# $FreeBSD$

PORTNAME=	ggz-sdl-games
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	9
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - SDL-based games

USE_GL=		gl
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread -lexpat

post-patch:
	@${REINPLACE_CMD} -e 's|_LDADD =|_LDADD = -lggzcore -lggz|' \
		${WRKSRC}/ttt3d/Makefile.in
	@${REINPLACE_CMD} -e 's|_LDADD =|_LDADD = -lggzcore|' \
		${WRKSRC}/geekgame/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/geekgame/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/geekgame.dsc
	${INSTALL_DATA} ${WRKSRC}/ttt3d/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/ttt3d.dsc

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
