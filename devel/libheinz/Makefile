PORTNAME=	libheinz
DISTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	https://jugit.fz-juelich.de/mlz/${PORTNAME}/-/archive/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ base library of Heinz Maier-Leibnitz Zentrum
WWW=		https://jugit.fz-juelich.de/mlz/libheinz

LICENSE=	MIT

USES=		cmake:testing

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING

NO_ARCH=	yes

PLIST_FILES=	cmake/LibHeinzConfig.cmake \
		cmake/LibHeinzConfigVersion.cmake \
		include/heinz/Complex.h \
		include/heinz/Rotations3D.h \
		include/heinz/Vectors3D.h

.include <bsd.port.mk>
