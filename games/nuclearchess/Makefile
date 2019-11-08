# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	nuclearchess
PORTVERSION=	1.0.0
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/nuclearchess/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chess variant designed to be short and fun for all players

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome sdl
USE_SDL=	sdl image
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${DATADIR}

PORTDOCS=	AUTHORS ChangeLog
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="NuclearChess" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" ""

post-patch:
	@${REINPLACE_CMD} '/^nuclearchess_LDADD =/s/$$/ -lm/' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
