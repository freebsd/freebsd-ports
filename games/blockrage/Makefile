# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	blockrage
PORTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION} \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Falling blocks game with 2-player hotseat mode

LICENSE=	GPLv2

USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}
MAN6=		${PORTNAME}.6

PORTDOCS=	ChangeLog KNOWN_BUGS README TODO

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Block Rage" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|prefix=/usr/local|prefix=${PREFIX}|' \
	-e 's|MYCC=gcc|MYCC?=${CC}|' \
	-e 's|-s -O2 -Wall||' \
	-e 's|sdl-config|$(SDL_CONFIG)|' \
	-e 's|MAKE=make|MAKE=${MAKE}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gcc -s|${CC}|' \
		${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
.for d in data blockrage-fhs.rc blockrage.cfg blockrage.rc
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}

.for s in ${ICON_SIZES}
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
