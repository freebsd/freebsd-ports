# $FreeBSD$

PORTNAME=	librecad
DISTVERSION=	2.0.3
CATEGORIES=	cad
MASTER_SITES=	GITHUB

MAINTAINER=	makc@FreeBSD.org
COMMENT=	2D CAD system

BUILD_DEPENDS=	${LOCALBASE}/lib/libmuparser.a:${PORTSDIR}/math/muparser \
		${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs

USE_QT4=	help qt3support help-tools_build linguist_build moc_build \
		rcc_build uic_build uic3_build
USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

USE_GITHUB=	yes
GH_ACCOUNT=	LibreCAD
GH_PROJECT=	LibreCAD
GH_COMMIT=	1555bd5

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
	(cd ${WRKSRC}/unix/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/desktop/librecad.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/librecad/res/main/librecad.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
