PORTNAME=	pynest2d
DISTVERSION=	5.3.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	CPython bindings for libnest2d by Ultimaker
WWW=		https://github.com/Ultimaker/libnest2d

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/include/libnest2d/libnest2d.hpp:devel/libnest2d-ultimaker
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip@${PY_FLAVOR}
LIB_DEPENDS=	libpolyclipping.so:graphics/polyclipping \
		libboost_system.so:devel/boost-libs \
		libnlopt.so:math/nlopt

USES=		python cmake compiler:c++11-lang pyqt:6 pkgconfig
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
CMAKE_ARGS=	-DLIBNEST2D_INCLUDE_DIRS=${PREFIX}/include/libnest2d

CONFIGURE_ENV=	CLIPPER_PATH=${LOCALBASE} VERBOSE=y

post-extract:
	@${MKDIR} ${WRKSRC}/cmake
	@for f in COPYING-CMAKE-SCRIPTS FindClipper.cmake FindNLopt.cmake FindSIP.cmake FindSIP.py Findlibnest2d.cmake SIPMacros.cmake; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}/cmake; \
	done
	@${CP} ${FILESDIR}/CMakeLists.txt ${WRKSRC}

.include <bsd.port.mk>
