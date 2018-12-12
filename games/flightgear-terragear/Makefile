# $FreeBSD$

PORTNAME=	flightgear-terragear
PORTVERSION=	20171007
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Tools for building scenery for the FlightGear project

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libSimGearCore.a:devel/simgear
LIB_DEPENDS=	libCGAL.so:math/cgal \
		libgdal.so:graphics/gdal \
		libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libboost_thread.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_atomic.so:devel/boost-libs \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	${LOCALBASE}/lib/libSimGearCore.a:devel/simgear

USES=	cmake

USE_GITHUB=	yes
GH_ACCOUNT=	flightgear
GH_PROJECT=	terragear
GH_TAGNAME=	5b5e5fc

.include <bsd.port.mk>
