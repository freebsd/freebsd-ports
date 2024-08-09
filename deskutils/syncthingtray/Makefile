PORTNAME=	syncthingtray
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	deskutils

MAINTAINER=	dsh@bamus.cz
COMMENT=	Qt ${FLAVOR:S/qt//}-based Syncthing tray application
WWW=		https://github.com/Martchus/syncthingtray

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/syncthingtray/LICENSE

BUILD_DEPENDS=	p5-YAML-LibYAML>0:textproc/p5-YAML-LibYAML
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}
FLAVORS_SUB=	yes

qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_PKGNAMESUFFIX=	-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}

USES=		cmake:insource iconv perl5 xorg

CMAKE_ARGS=	-DFORK_AWESOME_FONT_FILE=${WRKDIR}/forkawesome/fonts/forkawesome-webfont.ttf \
		-DFORK_AWESOME_ICON_DEFINITIONS=${WRKDIR}/forkawesome/src/icons/icons.yml
CMAKE_OFF=	SYSTEMD_SUPPORT USE_STANDARD_FILESYSTEM
CMAKE_ON=	NO_DOXYGEN
CMAKE_SOURCE_PATH=	${WRKDIR}/subdirs/syncthingtray

USE_GITHUB=	nodefault
GH_ACCOUNT=	Martchus
GH_TUPLE:=	${GH_ACCOUNT}:${PORTNAME}:${DISTVERSIONPREFIX}${DISTVERSION}:${PORTNAME}/../${PORTNAME} \
		${GH_ACCOUNT}:cpp-utilities:e79fcf7:cpputilities/../c++utilities \
		${GH_ACCOUNT}:qtutilities:v6.14.2:qtutilities/../qtutilities \
		${GH_ACCOUNT}:qtforkawesome:v0.2.0:qtforkawesome/../qtforkawesome \
		ForkAwesome:Fork-Awesome:4fef70f:ForkAwesome/../forkawesome \
		${GH_ACCOUNT}:subdirs:a88814b:subdirs/../subdirs

USE_KDE=	ecm:build
USE_QT=		declarative svg
USE_XORG=	x11

.if ${FLAVOR} == qt5
USES+=		kde:5 qt:5
USE_KDE+=	plasma-framework:build
USE_QT+=	concurrent core dbus gui location network qdbus \
		quickcontrols2:build widgets x11extras:build buildtools:build \
		linguist:build qmake:build testlib:build
WEBENGINE_USE=	QT=printsupport,webchannel,webengine
.else
CMAKE_ARGS+=	-DQT_PACKAGE_PREFIX:STRING=Qt6 -DKF_PACKAGE_PREFIX:STRING=KF6
USES+=		gl kde:6 qt:6
USE_GL=		opengl
USE_KDE+=	libplasma:build
USE_QT+=	base positioning
WEBENGINE_USE=	QT=webchannel,webengine
.endif

OPTIONS_DEFINE=		WEBENGINE
OPTIONS_DEFAULT=	WEBENGINE

WEBENGINE_DESC=		Built-in web view (webengine dependency)
WEBENGINE_CMAKE_ON=	-DWEBVIEW_PROVIDER:STRING=webengine
WEBENGINE_CMAKE_OFF=	-DWEBVIEW_PROVIDER:STRING=none

USE_PERL5=	build

BUILD_WRKSRC=		${WRKDIR}
CONFIGURE_WRKSRC=	${WRKDIR}
INSTALL_WRKSRC=		${WRKDIR}
PATCH_WRKSRC=		${WRKDIR}

post-install:
	${RM} -r \
		${STAGEDIR}${PREFIX}/include/c++utilities \
		${STAGEDIR}${PREFIX}/include/qtforkawesome \
		${STAGEDIR}${PREFIX}/include/qtquickforkawesome \
		${STAGEDIR}${PREFIX}/include/qtutilities \
		${STAGEDIR}${PREFIX}/include/syncthingconnector \
		${STAGEDIR}${PREFIX}/include/syncthingmodel \
		${STAGEDIR}${PREFIX}/include/syncthingwidgets \
		${STAGEDIR}${PREFIX}/lib/libc++utilities.a \
		${STAGEDIR}${PREFIX}/lib/libqtforkawesome.a \
		${STAGEDIR}${PREFIX}/lib/libqtquickforkawesome.a \
		${STAGEDIR}${PREFIX}/lib/libqtutilities.a \
		${STAGEDIR}${PREFIX}/lib/libsyncthingconnector.a \
		${STAGEDIR}${PREFIX}/lib/libsyncthingmodel.a \
		${STAGEDIR}${PREFIX}/lib/libsyncthingwidgets.a \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/c++utilities.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/qtforkawesome.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/qtforkawesomeiconengine.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/qtquickforkawesome.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/qtutilities.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingconnector.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingfileitemaction.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingmodel.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingplasmoid.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/syncthingwidgets.pc \
		${STAGEDIR}${PREFIX}/share/c++utilities \
		${STAGEDIR}${PREFIX}/share/qtforkawesome \
		${STAGEDIR}${PREFIX}/share/qtforkawesomeiconengine \
		${STAGEDIR}${PREFIX}/share/qtquickforkawesome \
		${STAGEDIR}${PREFIX}/share/qtutilities \
		${STAGEDIR}${PREFIX}/share/syncthingconnector/cmake \
		${STAGEDIR}${PREFIX}/share/syncthingfileitemaction/cmake \
		${STAGEDIR}${PREFIX}/share/syncthingmodel/cmake \
		${STAGEDIR}${PREFIX}/share/syncthingplasmoid/cmake \
		${STAGEDIR}${PREFIX}/share/syncthingwidgets/cmake \
		${STAGEDIR}${QT_PLUGINDIR} \
		${STAGEDIR}${QT_LIBDIR}

.include <bsd.port.mk>
