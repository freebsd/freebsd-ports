# Created by: yinjieh
# $FreeBSD$

PORTNAME=	ggz-sdl-games
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	11
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - SDL-based games

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USES=		gettext
USE_GGZ=	client
USE_GL=		gl
USE_SDL=	image mixer sdl ttf
USE_XORG=	xcursor

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexpat

post-patch:
	@${REINPLACE_CMD} -e '/^ggz_ttt3d_LDADD =/s/$$/ -lggzcore -lggz/' \
		${WRKSRC}/ttt3d/Makefile.in
	@${REINPLACE_CMD} -e '/^geekgame_LDADD =/s/$$/ -lggzcore -lX11/' \
		${WRKSRC}/geekgame/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/geekgame/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/geekgame.dsc
	${INSTALL_DATA} ${WRKSRC}/ttt3d/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/ttt3d.dsc
	${RM} ${STAGEDIR}${PREFIX}/etc/ggz.modules

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
