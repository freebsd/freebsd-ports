# $FreeBSD$

PORTNAME=	syncthingtray
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Qt 5-based Syncthing tray application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/syncthingtray/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake:devel/kf5-extra-cmake-modules \
		doxygen:devel/doxygen
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs

USES=		cmake:insource iconv kde:5 qt:5

USE_GITHUB=	nodefault
GH_TUPLE=	Martchus:${PORTNAME}:${DISTVERSIONPREFIX}${DISTVERSION}:syncthingtray/../syncthingtray \
		Martchus:cpp-utilities:v5.0.0:cpputilities/../c++utilities \
		Martchus:qtutilities:v6.0.0:qtutilities/../qtutilities \
		Martchus:subdirs:f3b12f9:subdirs/../subdirs

USE_KDE=	plasma-framework
USE_QT=		concurrent core dbus declarative gui location network \
		printsupport qdbus quickcontrols2 svg webchannel webengine \
		widgets x11extras buildtools_build doc_build linguist_build \
		qmake_build

CMAKE_OFF=	USE_STANDARD_FILESYSTEM

CONFIGURE_WRKSRC=	${WRKDIR}
BUILD_WRKSRC=		${WRKDIR}
INSTALL_WRKSRC=		${WRKDIR}
CMAKE_SOURCE_PATH=	${WRKDIR}/subdirs/syncthingtray

post-install:
	${RM} -r \
		${STAGEDIR}${PREFIX}/include/c++utilities \
		${STAGEDIR}${PREFIX}/include/qtutilities \
		${STAGEDIR}${PREFIX}/lib/libc++utilities.a \
		${STAGEDIR}${PREFIX}/lib/libqtutilities.a \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/c++utilities.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/qtutilities.pc \
		${STAGEDIR}${PREFIX}/share/c++utilities \
		${STAGEDIR}${PREFIX}/share/qtutilities \
		${STAGEDIR}${PREFIX}/share/syncthingconnector/cmake \
		${STAGEDIR}${PREFIX}/share/syncthingfileitemaction/cmake \
		${STAGEDIR}${PREFIX}/share/syncthingmodel/cmake \
		${STAGEDIR}${PREFIX}/share/syncthingplasmoid/cmake \
		${STAGEDIR}${PREFIX}/share/syncthingwidgets/cmake \
		${STAGEDIR}${PREFIX}/include/syncthingconnector \
		${STAGEDIR}${PREFIX}/include/syncthingmodel \
		${STAGEDIR}${PREFIX}/include/syncthingwidgets \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingconnector.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingfileitemaction.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingmodel.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingplasmoid.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingwidgets.pc \
		${STAGEDIR}${PREFIX}/lib/libsyncthingconnector.a \
		${STAGEDIR}${PREFIX}/lib/libsyncthingmodel.a \
		${STAGEDIR}${PREFIX}/lib/libsyncthingwidgets.a \
		${STAGEDIR}${QT_PLUGINDIR} \
		${STAGEDIR}${QT_LIBDIR}

.include <bsd.port.mk>
