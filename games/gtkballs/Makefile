PORTNAME=	gtkballs
PORTVERSION=	3.1.5
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	http://gtkballs.antex.ru/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lines-like simple logic game for X Window System
WWW=		http://gtkballs.antex.ru/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--localstatedir=/var/games

PORTDOCS=	AUTHORS ChangeLog NEWS README README.russian

DESKTOP_ENTRIES="GtkBalls" "" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnome-gtkballs.png  \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${MV} ${STAGEDIR}/var/games/gtkballs-scores \
		${STAGEDIR}/var/games/gtkballs-scores.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
