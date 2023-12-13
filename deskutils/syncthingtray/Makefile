PORTNAME=	syncthingtray
PORTVERSION=	1.4.11
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Qt 5-based Syncthing tray application
WWW=		https://github.com/Martchus/syncthingtray

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/syncthingtray/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake:devel/kf5-extra-cmake-modules \
		doxygen:devel/doxygen \
		p5-YAML-LibYAML>0:textproc/p5-YAML-LibYAML
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs

USES=		cmake:insource compiler:c++11-lang desktop-file-utils iconv \
		kde:5 perl5 qt:5

USE_GITHUB=	nodefault
GH_TUPLE=	Martchus:${PORTNAME}:${DISTVERSIONPREFIX}${DISTVERSION}:syncthingtray/../syncthingtray \
		Martchus:cpp-utilities:v5.24.3:cpputilities/../c++utilities \
		Martchus:qtutilities:v6.13.3:qtutilities/../qtutilities \
		Martchus:qtforkawesome:3ec0824:qtforkawesome/../qtforkawesome \
		ForkAwesome:Fork-Awesome:4fef70f:ForkAwesome/../forkawesome \
		Martchus:subdirs:c2b6d74:subdirs/../subdirs

USE_KDE=	plasma-framework
USE_PERL5=	build
USE_QT=		concurrent core dbus declarative gui location network \
		printsupport qdbus quickcontrols2 svg webchannel widgets \
		x11extras buildtools:build doc:build linguist:build \
		qmake:build testlib:build

CMAKE_ARGS=	-DFORK_AWESOME_FONT_FILE=${WRKDIR}/forkawesome/fonts/forkawesome-webfont.ttf \
		-DFORK_AWESOME_ICON_DEFINITIONS=${WRKDIR}/forkawesome/src/icons/icons.yml
CMAKE_OFF=	SYSTEMD_SUPPORT USE_STANDARD_FILESYSTEM
CMAKE_SOURCE_PATH=	${WRKDIR}/subdirs/syncthingtray

BUILD_WRKSRC=		${WRKDIR}
CONFIGURE_WRKSRC=	${WRKDIR}
INSTALL_WRKSRC=		${WRKDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
USE_QT+=	webengine
.else
CMAKE_ARGS+=	-DWEBVIEW_PROVIDER=webkit
USE_QT+=	webkit
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

.include <bsd.port.post.mk>
