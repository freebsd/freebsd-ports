PORTNAME=	syncthingtray
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.10
CATEGORIES=	deskutils

MAINTAINER=	dsh@bamus.cz
COMMENT=	Qt ${FLAVOR:S/qt//}-based Syncthing tray application
WWW=		https://martchus.github.io/syncthingtray/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/syncthingtray/LICENSE

BUILD_DEPENDS=	p5-YAML-LibYAML>0:textproc/p5-YAML-LibYAML
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

FLAVORS=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}
FLAVORS_SUB=	yes

qt6_PKGNAMESUFFIX=	-qt6

USES=		cmake:insource iconv perl5 xorg

USE_GITHUB=	nodefault
GH_ACCOUNT=	Martchus
GH_TUPLE:=	${GH_ACCOUNT}:${PORTNAME}:${DISTVERSIONPREFIX}${DISTVERSION}:${PORTNAME}/../${PORTNAME} \
		${GH_ACCOUNT}:cpp-utilities:v5.29.0:cpputilities/../c++utilities \
		${GH_ACCOUNT}:qtutilities:v6.17.0:qtutilities/../qtutilities \
		${GH_ACCOUNT}:qtforkawesome:v0.3.1:qtforkawesome/../qtforkawesome \
		ForkAwesome:Fork-Awesome:4fef70f:ForkAwesome/../forkawesome \
		${GH_ACCOUNT}:subdirs:53b30dd:subdirs/../subdirs

USE_PERL5=	build
USE_QT=		declarative svg
USE_XORG=	x11

CMAKE_ARGS=	-DFORK_AWESOME_FONT_FILE=${WRKDIR}/forkawesome/fonts/forkawesome-webfont.ttf \
		-DFORK_AWESOME_ICON_DEFINITIONS=${WRKDIR}/forkawesome/src/icons/icons.yml
CMAKE_ON=	NO_DOXYGEN
CMAKE_OFF=	SYSTEMD_SUPPORT USE_STANDARD_FILESYSTEM
CMAKE_SOURCE_PATH=	${WRKDIR}/subdirs/syncthingtray

.if ${FLAVOR} == qt5
USES+=		qt:5
USE_QT+=	concurrent core dbus gui location network qdbus \
		quickcontrols2:build widgets x11extras:build buildtools:build \
		linguist:build qmake:build testlib:build
.else
CMAKE_ARGS+=	-DQT_PACKAGE_PREFIX:STRING=Qt6 -DKF_PACKAGE_PREFIX:STRING=KF6
USES+=		gl qt:6
USE_GL=		opengl
USE_QT+=	base positioning tools:build
.endif

CONFLICTS_INSTALL=	${PORTNAME} ${PORTNAME}-*

BUILD_WRKSRC=		${WRKDIR}
CONFIGURE_WRKSRC=	${WRKDIR}
INSTALL_WRKSRC=		${WRKDIR}
PATCH_WRKSRC=		${WRKDIR}

OPTIONS_DEFINE=		PLASMA WEBENGINE
OPTIONS_DEFAULT=	PLASMA WEBENGINE
OPTIONS_SUB=	yes

PLASMA_DESC=	Plasma integration (KF dependency)
WEBENGINE_DESC=		Built-in web view (webengine dependency)

PLASMA_USE=	KDE=ecm:build
PLASMA_CMAKE_BOOL_OFF=	NO_FILE_ITEM_ACTION_PLUGIN NO_PLASMOID

WEBENGINE_CMAKE_ON=	-DWEBVIEW_PROVIDER:STRING=webengine
WEBENGINE_CMAKE_OFF=	-DWEBVIEW_PROVIDER:STRING=none

.if ${FLAVOR} == qt5
PLASMA_USES=	kde:5
PLASMA_USE+=	KDE=plasma-framework:build
WEBENGINE_USE=	QT=printsupport,webchannel,webengine
.else
PLASMA_USES=	kde:6
PLASMA_USE+=	KDE=libplasma:build
WEBENGINE_USE=	QT=webchannel,webengine
.endif

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
