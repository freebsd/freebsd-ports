# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	help_hannahs_horse
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SF/hannah/hannah/hannah-${DISTVERSION}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	hhh-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Pacman with a fast food twist

LICENSE=	GPLv2 OFL11
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/hhh-2008-03-29

USES=		gmake
USE_SDL=	sdl image mixer ttf
ALL_TARGET=	# empty

PORTDOCS=	CHANGELOG README
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Help Hannah's Horse" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/hhh|${DATADIR}|; \
		s|/usr/local/bin|${PREFIX}/bin|; \
		s|CXX       = g++|CXX       ?= g++}|; \
		s|CXXFLAGS   = -O2 -Wall -g|CXXFLAGS   +=|; \
		s|OUT = hhh|OUT = ${PORTNAME}|; \
		s|-include deps|#-include deps|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in blue carrot default freeze hannah images invert invis maps newanim \
		 pink red sounds stop
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
.for f in *.ogg *.ttf *.dat *.png
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${STAGEDIR}${DATADIR})
.endfor

post-install:
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
