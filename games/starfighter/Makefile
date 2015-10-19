# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	starfighter
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/pr-${PORTNAME}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Liberate the universe from the evil company WEAPCO

LICENSE=	GPLv2

USES=		gmake iconv python:2,build shebangfix
USE_XORG=	x11 xau xdmcp
USE_SDL=	image mixer
WITH_ZLIB=	yes
MAKEFILE=	makefile

SHEBANG_FILES=	pack.py unpack.py

INSTALLS_ICONS=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		%%DATADIR%%/${PORTNAME}.pak
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	index.html

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Project Starfighter" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|mkdir -p $$(DESTDIR)$$(DOCDIR)|| ; \
	s|cp -p $$(DOCS) $$(DESTDIR)$$(DOCDIR)|| ; \
	s| -O2 -Wall|${CXXFLAGS}| ; \
	s|docs/\*|docs/index.html| ; \
	s|/usr|${LOCALBASE}| ; \
	s|$$(PREFIX)/games/|$$(PREFIX)/bin/| ; \
	s|/share/games/parallelrealities/|/share/starfighter/|' \
		${WRKSRC}/makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
