PORTNAME=	syncthingtray
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	dsh@bamus.cz
COMMENT=	Qt6-based Syncthing tray application
WWW=		https://martchus.github.io/syncthingtray/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/syncthingtray/LICENSE

BUILD_DEPENDS=	p5-YAML-LibYAML>0:textproc/p5-YAML-LibYAML
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USES=		cmake:insource gl iconv perl5 qt:6 xorg

USE_GITHUB=	nodefault
GH_ACCOUNT=	Martchus
GH_TUPLE:=	${GH_ACCOUNT}:${PORTNAME}:${DISTVERSIONPREFIX}${DISTVERSION}:${PORTNAME}/../${PORTNAME} \
		${GH_ACCOUNT}:cpp-utilities:v5.34.2:cpputilities/../c++utilities \
		${GH_ACCOUNT}:qtutilities:v6.21.3:qtutilities/../qtutilities \
		${GH_ACCOUNT}:qtforkawesome:v0.3.4:qtforkawesome/../qtforkawesome \
		ForkAwesome:Fork-Awesome:4fef70f:ForkAwesome/../forkawesome \
		${GH_ACCOUNT}:subdirs:5f47515:subdirs/../subdirs

USE_GL=		opengl
USE_PERL5=	build
USE_QT=		base declarative svg tools:build
USE_XORG=	x11

CMAKE_ARGS=	-DFORK_AWESOME_FONT_FILE=${WRKDIR}/forkawesome/fonts/forkawesome-webfont.ttf \
		-DFORK_AWESOME_ICON_DEFINITIONS=${WRKDIR}/forkawesome/src/icons/icons.yml \
		-DKF_PACKAGE_PREFIX:STRING=KF6 \
		-DQT_PACKAGE_PREFIX:STRING=Qt6 \
		-DQUICK_GUI=ON -DQUICK_GUI_CONTROLS_STYLE=dynamic
CMAKE_ON=	NO_DOXYGEN
CMAKE_OFF=	SYSTEMD_SUPPORT USE_STANDARD_FILESYSTEM
CMAKE_SOURCE_PATH=	${WRKDIR}/subdirs/syncthingtray

BUILD_WRKSRC=		${WRKDIR}
CONFIGURE_WRKSRC=	${WRKDIR}
INSTALL_WRKSRC=		${WRKDIR}
PATCH_WRKSRC=		${WRKDIR}

PLIST_SUB=	LIBVERSION=${DISTVERSION}

OPTIONS_DEFINE=		PLASMA WEBENGINE
OPTIONS_DEFAULT=	PLASMA WEBENGINE
OPTIONS_SUB=		yes

PLASMA_DESC=		Plasma integration (KF dependency)
WEBENGINE_DESC=		Built-in web view (webengine dependency)

PLASMA_USES=		kde:6
PLASMA_USE=		KDE=bookmarks,completion,config,coreaddons,ecm:build \
			KDE=jobwidgets,itemviews,kio,libplasma,jobwidgets \
			KDE=kirigami2,service,solid,widgetsaddons
# PLASMA option now requires `-DBUILD_SHARED_LIBS=ON`. See
# https://github.com/Martchus/syncthingtray/issues/451
PLASMA_CMAKE_BOOL_OFF=	NO_FILE_ITEM_ACTION_PLUGIN NO_PLASMOID
PLASMA_CMAKE_ON=	-DBUILD_SHARED_LIBS=ON
PLASMA_CONFLICTS_INSTALL=	cpp-utilities qtutilities

WEBENGINE_USE=		QT=positioning,webchannel,webengine
WEBENGINE_CMAKE_ON=	-DWEBVIEW_PROVIDER:STRING=webengine
WEBENGINE_CMAKE_OFF=	-DWEBVIEW_PROVIDER:STRING=none

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
		${STAGEDIR}${PREFIX}/lib/libsyncthingwidgetsplugin.a \
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
		${STAGEDIR}${QT_PLUGINDIR}/iconengines

.include <bsd.port.mk>
