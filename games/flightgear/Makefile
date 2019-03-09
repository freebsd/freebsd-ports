# Created by: Brian Buchanan <brian@CSUA.Berkeley.EDU>
# $FreeBSD$

PORTNAME=	flightgear
PORTVERSION=	2018.3.2
CATEGORIES=	games
MASTER_SITES=	SF/flightgear/release-${PORTVERSION:R}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	FlightGear flight simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libboost_thread.so:devel/boost-libs \
		libfltk.so:x11-toolkits/fltk \
		libfreetype.so:print/freetype2 \
		libosg.so:graphics/osg \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libcurl.so:ftp/curl \
		libudev.so:devel/libudev-devd
BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib \
		${LOCALBASE}/lib/libSimGearCore.a:devel/simgear \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib \
		${LOCALBASE}/lib/libSimGearCore.a:devel/simgear \
		${LOCALBASE}/share/flightgear/version:games/flightgear-data

# Disable ninja, see https://sourceforge.net/p/flightgear/codetickets/2118/
USES=		alias cmake:noninja compiler cpe dos2unix gl jpeg openal:al,alut \
		sqlite tar:bzip2
USE_XORG=	ice sm x11 xext xft xi xinerama xmu xt
USE_GL=		gl glew glu glut

LLD_UNSAFE=	yes

DOS2UNIX_REGEX=	.*\.(c|h|cxx|cpp|hxx|hpp)
CMAKE_ARGS+=	-DSYSTEM_SQLITE:BOOL=ON \
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
QT5_USES=	qt:5
QT5_USE=	QT=core,buildtools,gui,declarative,network,qmake,widgets,svg

post-patch:
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/version ${WRKSRC}/version.txt
	@${REINPLACE_CMD} -Ei .c++20 '/file|set_prop/s/version[[:>:]]/&.txt/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
