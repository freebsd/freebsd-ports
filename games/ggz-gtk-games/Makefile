# Created by: yinjieh
# $FreeBSD$

PORTNAME=	ggz-gtk-games
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	6
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - GTK+ Games

RUN_DEPENDS=	${LOCALBASE}/bin/ggz-gtk:games/ggz-gtk-client

USES=		gettext pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

post-patch:
	@${REINPLACE_CMD} -e 's|_LDADD =|_LDADD = -lggzcore|' \
		${WRKSRC}/chess/Makefile.in \
		${WRKSRC}/chinese-checkers/Makefile.in \
		${WRKSRC}/combat/Makefile.in \
		${WRKSRC}/dots/Makefile.in \
		${WRKSRC}/ggzcards/Makefile.in \
		${WRKSRC}/hastings/Makefile.in \
		${WRKSRC}/reversi/Makefile.in \
		${WRKSRC}/spades/Makefile.in \
		${WRKSRC}/tictactoe/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/chess/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/chess.dsc
	${INSTALL_DATA} ${WRKSRC}/chinese-checkers/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/chinese-checkers.dsc
	${INSTALL_DATA} ${WRKSRC}/combat/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/combat.dsc
	${INSTALL_DATA} ${WRKSRC}/dots/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/dots.dsc
	${INSTALL_DATA} ${WRKSRC}/ggzcards/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/ggzcards.dsc
	${INSTALL_DATA} ${WRKSRC}/hastings/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/hastings.dsc
	${INSTALL_DATA} ${WRKSRC}/reversi/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/reversi.dsc
	${INSTALL_DATA} ${WRKSRC}/spades/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/spades.dsc
	${INSTALL_DATA} ${WRKSRC}/tictactoe/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/tictactoe.dsc
	${RM} ${STAGEDIR}${PREFIX}/etc/ggz.modules

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
