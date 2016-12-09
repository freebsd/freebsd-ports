# Created by: Brian Buchanan <brian@CSUA.Berkeley.EDU>
# $FreeBSD$

PORTNAME=	flightgear
PORTVERSION=	2016.4.3
CATEGORIES=	games
MASTER_SITES=	SF/flightgear/release-${PORTVERSION:R}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	The FlightGear flight simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libboost_thread.so:devel/boost-libs \
		libfltk.so:x11-toolkits/fltk \
		libosg.so:graphics/osg \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libcurl.so:ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib \
		${LOCALBASE}/lib/libSimGearCore.a:devel/simgear
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib \
		${LOCALBASE}/lib/libSimGearCore.a:devel/simgear \
		${LOCALBASE}/share/flightgear/version:games/flightgear-data

USE_XORG=	ice sm x11 xext xft xi xinerama xmu xt
USE_GL=		gl glu glut

USES=		alias cmake compiler cpe dos2unix jpeg openal:al,alut sqlite \
		tar:bzip2
DOS2UNIX_REGEX=	.*\.(c|h|cxx|cpp|hxx|hpp)
CMAKE_ARGS+=	-DENABLE_JS_SERVER:BOOL=ON \
		-DSYSTEM_SQLITE:BOOL=ON \
		-DFG_DATA_DIR:PATH=${LOCALBASE}/share/${PORTNAME} \
		-DCMAKE_INSTALL_MANDIR:PATH=${MANPREFIX}/man \
		-DFGCOM_DATA_PATH:PATH=${DATADIR}
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DBUS QT5
OPTIONS_DEFAULT=	DBUS QT5
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_USES=	pkgconfig
DBUS_CMAKE_ON=	-DUSE_DBUS:BOOL=ON
DBUS_CMAKE_OFF=	-DUSE_DBUS:BOOL=OFF
QT5_CMAKE_ON=	-DENABLE_QT:BOOL=ON
QT5_CMAKE_OFF=	-DENABLE_QT:BOOL=OFF
QT5_USE=	QT5=core,buildtools,gui,qmake,widgets

.include <bsd.port.pre.mk>

# Chase devel/simgear compiler version
.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 46
USE_GCC=	yes
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/js_server/js_server \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
