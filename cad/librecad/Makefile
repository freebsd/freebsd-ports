PORTNAME=	librecad
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1.2
CATEGORIES=	cad

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	2D CAD system
WWW=		https://librecad.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/licenses/gpl-2.0.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
LIB_DEPENDS=	libmuparser.so:math/muparser \
		libfreetype.so:print/freetype2

USES=		compiler:c++17-lang cpe desktop-file-utils pkgconfig gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	LibreCAD
GH_PROJECT=	LibreCAD
USE_GL=		gl
USE_QT=		core gui printsupport svg widgets \
		buildtools:build linguisttools:build

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
	${INSTALL_DATA} ${WRKSRC}/unix/appdata/org.librecad.librecad.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/unix/appdata/librecad.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/librecad/res/main/librecad.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
