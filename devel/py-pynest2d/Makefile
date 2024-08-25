PORTNAME=	pynest2d
# XXX there is no 4.13.1
DISTVERSION=	4.12.1
PORTREVISION=	5
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	CPython bindings for libnest2d by Ultimaker
WWW=		https://github.com/Ultimaker/libnest2d

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Fails to build with modern python
EXPIRATION_DATE=	2024-06-29

RUN_DEPENDS=	${LOCALBASE}/include/libnest2d/libnest2d.hpp:devel/libnest2d-ultimaker
BUILD_DEPENDS=	${LOCALBASE}/include/libnest2d/libnest2d.hpp:devel/libnest2d-ultimaker \
		sip:devel/py-sip4
LIB_DEPENDS=	libpolyclipping.so:graphics/polyclipping \
		libboost_system.so:devel/boost-libs \
		libnlopt.so:math/nlopt

USES=		python cmake compiler:c++11-lang pyqt:5 pkgconfig
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_TUPLE=	Ultimaker:pynest2d:baec470
CMAKE_ARGS=	-DLIBNEST2D_INCLUDE_DIRS=${PREFIX}/include/libnest2d

CONFIGURE_ENV=	CLIPPER_PATH=${LOCALBASE} VERBOSE=y
.include <bsd.port.mk>
