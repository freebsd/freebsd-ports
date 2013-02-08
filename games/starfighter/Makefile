# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	starfighter
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/pr-${PORTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Liberate the universe from the evil company WEAPCO

LICENSE=	GPLv2

USE_ICONV=	yes
USE_XORG=	x11 xau xdmcp
USE_SDL=	image mixer
WITH_ZLIB=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Project Starfighter" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's| -O2 -Wall|${CXXFLAGS}|' \
	-e 's|docs/\*|docs/index.html|' \
	-e 's|/usr|${LOCALBASE}|' \
	-e 's|$$(PREFIX)/games/|$$(PREFIX)/bin/|' \
	-e 's|/share/games/parallelrealities/|/share/starfighter/|' \
		${WRKSRC}/makefile

.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' -e '/$$(DESTDIR)$$(DOCDIR)/d' ${WRKSRC}/makefile
.endif

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
