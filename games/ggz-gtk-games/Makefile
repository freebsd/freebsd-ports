# Created by: yinjieh
# $FreeBSD$

PORTNAME=	ggz-gtk-games
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	6
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - GTK+ Games

RUN_DEPENDS=	${LOCALBASE}/bin/ggz-gtk:${PORTSDIR}/games/ggz-gtk-client

USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ARGS=	--disable-nls

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

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
