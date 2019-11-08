# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	help_hannahs_horse
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/hannah/hannah/hannah-${DISTVERSION}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	hhh-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pacman with a fast food twist

LICENSE=	GPLv2 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/gpl.txt
#LICENSE_FILE_OFL11=	${WRKSRC}/StansHandOFL.txt ${WRKSRC}/Ray_Dittmeier_Fonts.txt # framework doesn't support multiple files

WRKSRC=		${WRKDIR}/hhh-2008-03-29

USES=		gmake gnome sdl
USE_SDL=	sdl image mixer ttf
ALL_TARGET=	# empty
MAKE_ENV=	DATA_INSTALL_DIR="${DATADIR}" \
		BIN_DIR="${PREFIX}/bin"

PORTDOCS=	CHANGELOG README

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Help Hannah's Horse" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hhh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "blue carrot default freeze hannah \
		images invert invis maps newanim pink red sounds stop \
		*.ogg *.ttf *.dat *.png" ${STAGEDIR}${DATADIR})
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
