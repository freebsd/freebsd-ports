# $FreeBSD$

PORTNAME=	pynest2d
DISTVERSION=	4.8.0
PORTREVISION=	3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	y@trombik.org
COMMENT=	CPython bindings for libnest2d by Ultimaker

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/include/libnest2d/libnest2d.hpp:devel/libnest2d-ultimaker
BUILD_DEPENDS=	${LOCALBASE}/include/libnest2d/libnest2d.hpp:devel/libnest2d-ultimaker
LIB_DEPENDS=	libpolyclipping.so:graphics/polyclipping \
		libboost_system.so:devel/boost-libs \
		libnlopt.so:math/nlopt

USES=		python:3.6+ cmake compiler:c++11-lang pyqt:5 pkgconfig
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_TUPLE=	Ultimaker:pynest2d:d31a381
USE_PYQT=	sip pysip
CMAKE_ARGS=	-DSIP_EXECUTABLE=${SIP} \
			-DLIBNEST2D_INCLUDE_DIRS=${PREFIX}/include/libnest2d

CONFIGURE_ENV=	CLIPPER_PATH=${LOCALBASE} VERBOSE=y
.include <bsd.port.mk>
