# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	traingame
PORTVERSION=	0.2.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.nickg.me.uk/files/:game \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	TrainGame-${DISTVERSION}${EXTRACT_SUFX}:game \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game about Trains

LICENSE=	GPLv3

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3 \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/TrainGame-${PORTVERSION}

USES=		cmake pkgconfig
USE_SDL=	sdl image
USE_GL=		glew
USE_GCC=	yes

PORTDOCS=	model_notes.txt models.gnuplot

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME} \
		${PORTNAME}-map \
		pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
		@${REINPLACE_CMD} -e 's|shared_ptr|std::shared_ptr|' \
			${WRKSRC}/src/Mesh.cpp

do-install:
.for d in ${PORTNAME} ${PORTNAME}-map
	${INSTALL_SCRIPT} ${WRKDIR}/${d} ${STAGEDIR}${PREFIX}/bin/
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
