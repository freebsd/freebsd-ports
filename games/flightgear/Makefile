# Created by: Brian Buchanan <brian@CSUA.Berkeley.EDU>
# $FreeBSD$

PORTNAME=	flightgear
PORTVERSION=	2.12.0
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
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
		libosg.so:${PORTSDIR}/graphics/osg
BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libSimGearCore.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libSimGearCore.a:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/share/flightgear/version:${PORTSDIR}/games/flightgear-data

USE_BZIP2=	yes
USE_XORG=	ice sm x11 xext xft xi xinerama xt xmu
USE_GL=		gl glu glut
USE_OPENAL=	al alut
USES=		cmake
CMAKE_ARGS+=	-DJPEG_FACTORY:BOOL=ON \
		-DENABLE_JS_SERVER:BOOL=ON \
		-DFG_DATA_DIR:PATH=${LOCALBASE}/share/${PORTNAME} \
		-DCMAKE_INSTALL_MANDIR:PATH=${MANPREFIX}/man

.include <bsd.port.options.mk>

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/js_server/js_server ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
