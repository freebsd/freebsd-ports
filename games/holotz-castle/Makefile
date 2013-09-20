# Created by: Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
# $FreeBSD$

PORTNAME=	holotz-castle
PORTVERSION=	1.3.14
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/holotz-castle/
DISTFILES=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Platform game with high doses of mystery

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

MAKE_ARGS=	HC_BASE=${PREFIX}/share/${PORTNAME}/ HC_BIN_DIR=${PREFIX}/bin/
MAKE_JOBS_UNSAFE=	yes

USE_GL=		gl
USE_SDL=	image mixer sdl ttf
USE_GMAKE=	yes

MAN6=		${PORTNAME}.6 ${PORTNAME}-editor.6

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

SUB_FILES=	pkg-message ${PORTNAME}-solutions

DESKTOP_ENTRIES="Holotz's Castle" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

DESKTOP_ENTRIES="Holotz's Castle Solutions" "${COMMENT}" ${PORTNAME} \
		"xterm -e ${PORTNAME}-solutions" "Game;LogicGame;" false

OPTIONS_DEFINE=	SOLUTIONS
OPTIONS_DEFAULT=SOLUTIONS
SOLUTIONS_DESC=	Solutions for Holotz's Castle

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOLUTIONS}
DISTFILES+=	${PORTNAME}_solutions${EXTRACT_SUFX}
EXTRACT_ONLY+=	${PORTNAME}_solutions${EXTRACT_SUFX}
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		xterm:${PORTSDIR}/x11/xterm
PLIST_SUB+=	SOLUTIONS=""
.else
PLIST_SUB+=	SOLUTIONS="@comment "
.endif

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN6} ${MAN6PREFIX}/man/man6)

.if ${PORT_OPTIONS:MSOLUTIONS}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-solutions ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/solutions
	@(cd ${WRKDIR} ; ${INSTALL_DATA} *.avi ${DATADIR}/solutions)
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
