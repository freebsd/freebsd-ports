# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	traingame
PORTVERSION=	0.3
PORTREVISION=	22
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game about Trains

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libxerces-c.so:textproc/xerces-c3 \
		libboost_filesystem.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	nickg
GH_TAGNAME=	cb6513e

USES=		cmake:insource compiler:c++11-lib dos2unix gl gnome pkgconfig \
		sdl
DOS2UNIX_GLOB=	*.mtl *.obj
USE_CXXSTD=	c++11
USE_SDL=	sdl image
USE_GL=		glew

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-Wno-return-type

PORTDOCS=	model_notes.txt models.gnuplot
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	22x22 32x32 48x48 64x64 72x72 96x96 128x128 192x192

SUB_FILES=	${PORTNAME} pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|[io]fstream|std::&|g' \
		${WRKSRC}/src/*.cpp ${WRKSRC}/include/*.hpp

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-map.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-map

.for d in buildings engines fonts images layouts maps schemas trees waggons
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/TrainGame ${STAGEDIR}${DATADIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install:
	@${ECHO_CMD}
	@${ECHO_CMD} ===============================================================================
	@${ECHO_CMD}
	@${ECHO_CMD} "These Maps you can use:"
	@${ECHO_CMD}
	@${LS} ${STAGEDIR}${DATADIR}/maps
	@${ECHO_CMD}
	@${ECHO_CMD} ===============================================================================

.include <bsd.port.mk>
