PORTNAME=	librecad
DISTVERSION=	2.2.0-rc3
CATEGORIES=	cad

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	8c3b652a8813.patch:-p1 # https://github.com/LibreCAD/LibreCAD/issues/1488

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	2D CAD system

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/licenses/gpl-2.0.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
LIB_DEPENDS=	libmuparser.so:math/muparser \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lib cpe desktop-file-utils pkgconfig gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	LibreCAD
GH_PROJECT=	LibreCAD
USE_GL=		gl
USE_QT=		core gui printsupport svg widgets \
		buildtools_build linguisttools_build

QMAKE_ARGS+=	BOOST_DIR="${LOCALBASE}"

post-patch:
	@${REINPLACE_CMD} -e 's|QMAKE_CXXFLAGS += -g||' \
		${WRKSRC}/common.pri
	@${REINPLACE_CMD} -e 's|lrelease|${LRELEASE}|' \
		${WRKSRC}/scripts/postprocess-unix.sh

pre-install:
	@${CHMOD} +w ${WRKSRC}/unix/resources/plugins/*.so
	@${STRIP_CMD} ${WRKSRC}/unix/resources/plugins/*.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/librecad ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/ttf2lff ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/unix/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/unix/appdata/librecad.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/desktop/librecad.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/librecad/res/main/librecad.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
