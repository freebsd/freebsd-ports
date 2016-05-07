# $FreeBSD$

PORTNAME=	librecad
DISTVERSION=	2.0.8
CATEGORIES=	cad

MAINTAINER=	makc@FreeBSD.org
COMMENT=	2D CAD system

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs
LIB_DEPENDS=	libmuparser.so:math/muparser

USE_QT4=	gui help network sql svg help-tools_build \
		linguisttools_build moc_build rcc_build uic_build
USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake

USE_GITHUB=	yes
GH_ACCOUNT=	LibreCAD
GH_PROJECT=	LibreCAD

# Unhide std::to_string() to fix build with GCC (ports/193528)
CFLAGS=		-D_GLIBCXX_USE_C99

post-patch:
	${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/librecad/src/lib/engine/rs_settings.cpp \
		${WRKSRC}/librecad/src/lib/engine/rs_system.cpp
	${REINPLACE_CMD} -e \
		'/^Icon/s,librecad,${PREFIX}/share/pixmaps/librecad.png,' \
		${WRKSRC}/desktop/librecad.desktop

pre-install:
	${CHMOD} +w ${WRKSRC}/unix/resources/plugins/*.so
	${STRIP_CMD} ${WRKSRC}/unix/resources/plugins/*.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/librecad ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/ttf2lff ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/unix/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata && \
		${INSTALL_DATA} ${WRKSRC}/unix/appdata/librecad.appdata.xml \
		${STAGEDIR}${PREFIX}/share/appdata)
	${INSTALL_DATA} ${WRKSRC}/desktop/librecad.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/librecad/res/main/librecad.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
