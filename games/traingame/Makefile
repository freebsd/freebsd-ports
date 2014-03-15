# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	traingame
PORTVERSION=	0.2.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game about Trains

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	nickg
GH_PROJECT=	traingame
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	83abcc9

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3 \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs

USES=		cmake compiler:c++11-lib pkgconfig
USE_CXXSTD=	c++11
USE_SDL=	sdl image
USE_GL=		glew

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-Wno-return-type

PORTDOCS=	model_notes.txt models.gnuplot
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME} ${PORTNAME}-map pkg-message

do-install:
.for f in ${PORTNAME} ${PORTNAME}-map
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for d in buildings engines fonts images layouts maps schemas trees waggons
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/TrainGame ${STAGEDIR}${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@${ECHO_CMD}
	@${ECHO_CMD} ===============================================================================
	@${ECHO_CMD}
	@${ECHO_CMD} "These Maps you can use:"
	@${ECHO_CMD}
	@${LS} ${STAGEDIR}${DATADIR}/maps
	@${ECHO_CMD}
	@${ECHO_CMD} ===============================================================================

.include <bsd.port.mk>
