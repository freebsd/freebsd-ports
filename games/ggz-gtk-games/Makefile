# ex:ts=8
# Ports collection makefile for:	ggz-gtk-games
# Date created:			Feb. 19, 2006
# Whom:				yinjieh
#
# $FreeBSD$
#

PORTNAME=	ggz-gtk-games
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	5
CATEGORIES=	games

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - GTK+ Games

RUN_DEPENDS=	${LOCALBASE}/bin/ggz-gtk:${PORTSDIR}/games/ggz-gtk-client

USE_GNOME=	gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
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

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/libggz/bsd.ggz.mk"
.include <bsd.port.post.mk>
