# Created by: Brian Buchanan <brian@CSUA.Berkeley.EDU>
# $FreeBSD$

PORTNAME=	flightgear
PORTVERSION=	3.2.0
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/flightgear/ftp/Source/ \
		http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Source/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Source/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Source/ \
		ftp://flightgear.wo0t.de/flightgear-ftp/ftp/Source/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	The FlightGear flight simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libosg.so:${PORTSDIR}/graphics/osg \
		libspeex.so:${PORTSDIR}/audio/speex
BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libSimGearCore.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libSimGearCore.a:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/share/flightgear/version:${PORTSDIR}/games/flightgear-data

USE_XORG=	ice sm x11 xext xft xi xinerama xt xmu
USE_GL=		gl glu glut
USE_SQLITE=	3

USES=		tar:bzip2 dos2unix cmake compiler openal:al,alut
DOS2UNIX_REGEX=	.*\.(c|h|cxx|cpp|hxx|hpp)
CMAKE_ARGS+=	-DENABLE_JS_SERVER:BOOL=ON \
		-DSYSTEM_SQLITE:BOOL=ON \
		-DFG_DATA_DIR:PATH=${LOCALBASE}/share/${PORTNAME} \
		-DCMAKE_INSTALL_MANDIR:PATH=${MANPREFIX}/man \
		-DFGCOM_DATA_PATH:PATH=${DATADIR}

OPTIONS_DEFINE=	DBUS
OPTIONS_DEFAULT=	DBUS
DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CMAKE_ON=	-DUSE_DBUS:BOOL=ON
DBUS_CMAKE_OFF=	-DUSE_DBUS:BOOL=OFF

.include <bsd.port.pre.mk>

# Chase devel/simgear compiler version
.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 46
USE_GCC=	4.6+
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/js_server/js_server ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
