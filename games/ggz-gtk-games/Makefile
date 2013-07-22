# Created by: yinjieh
# $FreeBSD$

PORTNAME=	ggz-gtk-games
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	6
CATEGORIES=	games

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - GTK+ Games

RUN_DEPENDS=	${LOCALBASE}/bin/ggz-gtk:${PORTSDIR}/games/ggz-gtk-client

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/chess/module.dsc ${PREFIX}/share/ggz/chess.dsc
	${INSTALL_DATA} ${WRKSRC}/chinese-checkers/module.dsc ${PREFIX}/share/ggz/chinese-checkers.dsc
	${INSTALL_DATA} ${WRKSRC}/combat/module.dsc ${PREFIX}/share/ggz/combat.dsc
	${INSTALL_DATA} ${WRKSRC}/dots/module.dsc ${PREFIX}/share/ggz/dots.dsc
	${INSTALL_DATA} ${WRKSRC}/ggzcards/module.dsc ${PREFIX}/share/ggz/ggzcards.dsc
	${INSTALL_DATA} ${WRKSRC}/hastings/module.dsc ${PREFIX}/share/ggz/hastings.dsc
	${INSTALL_DATA} ${WRKSRC}/reversi/module.dsc ${PREFIX}/share/ggz/reversi.dsc
	${INSTALL_DATA} ${WRKSRC}/spades/module.dsc ${PREFIX}/share/ggz/spades.dsc
	${INSTALL_DATA} ${WRKSRC}/tictactoe/module.dsc ${PREFIX}/share/ggz/tictactoe.dsc

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
