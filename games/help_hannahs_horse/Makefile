# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	help_hannahs_horse
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SF/hannah/hannah/hannah-${DISTVERSION}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	hhh-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Pacman with a fast food twist

LICENSE=	GPLv2 OFL11
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/hhh-2008-03-29

USE_SDL=	sdl image mixer ttf
USE_GMAKE=	yes
ALL_TARGET=	# empty

PORTDOCS=	CHANGELOG README TODO

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Help Hannah's Horse" "${COMMENT}" "${PORTNAME}.png" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/hhh|${DATADIR}|' \
		-e 's|/usr/local/bin|${PREFIX}/bin|' \
		-e 's|CXX       = g++|CXX       ?= g++|' \
		-e 's|CXXFLAGS   = -O2 -Wall -g|CXXFLAGS   +=|' \
		-e 's|OUT = hhh|OUT = ${PORTNAME}|' \
		-e 's|-include deps|#-include deps|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.for d in blue carrot default freeze hannah images invert invis maps newanim pink red sounds stop
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor
.for d in *.ogg *.ttf *.dat *.png
	@(cd ${WRKSRC} && ${INSTALL_DATA} ${d} ${DATADIR})
.endfor

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
