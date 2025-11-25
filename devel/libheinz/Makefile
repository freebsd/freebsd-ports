PORTNAME=	libheinz
DISTVERSION=	3.0.0
CATEGORIES=	devel
MASTER_SITES=	https://jugit.fz-juelich.de/mlz/${PORTNAME}/-/archive/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ base library of Heinz Maier-Leibnitz Zentrum
WWW=		https://jugit.fz-juelich.de/mlz/libheinz

LICENSE=	MIT

USES=		cmake:testing compiler:c++20-lang

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

NO_ARCH=	yes

PLIST_FILES=	lib/cmake/LibHeinz/LibHeinzConfig.cmake \
		lib/cmake/LibHeinz/LibHeinzConfigVersion.cmake \
		include/heinz/Complex.h \
		include/heinz/Rotations3D.h \
		include/heinz/Vectors3D.h

# tests as of 3.0.0: 100% tests passed, 0 tests failed out of 3

.include <bsd.port.mk>
