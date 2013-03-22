# Created by: Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
# $FreeBSD$

PORTNAME=	holotz-castle
PORTVERSION=	1.3.14
CATEGORIES=	games
MASTER_SITES=	http://www.mainreactor.net/holotzcastle/download/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

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

SUB_FILES=	pkg-message

DESKTOP_ENTRIES="Holotz's Castle" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN6} ${MAN6PREFIX}/man/man6)

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
