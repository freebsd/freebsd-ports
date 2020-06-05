# $FreeBSD$

PORTNAME=	reactphysics3d
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ physics engine library in 3D

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	DanielChappuis
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DRP3D_COMPILE_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./test/tests

.include <bsd.port.mk>
