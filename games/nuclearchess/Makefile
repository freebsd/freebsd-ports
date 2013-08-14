# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	nuclearchess
PORTVERSION=	1.0.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/nuclearchess/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Chess variant designed to be short and fun for all players

LICENSE=	GPLv2

USE_SDL=	sdl image
USE_GNOME=	desktopfileutils
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${DATADIR}

PORTDOCS=	AUTHORS ChangeLog

DESKTOP_ENTRIES="NuclearChess" "${COMMENT}"  \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Game;BoardGame;" false

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@-update-desktop-database

.include <bsd.port.mk>
