# $FreeBSD$

PORTNAME=	eastl
DISTVERSION=	3.13.06
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronic Arts Standard Template Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	test/packages/EABase/include/Common/EABase/config/eaplatform.h:436:4: error: Unknown processor

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	electronicarts
GH_PROJECT=	${PORTNAME:tu}
USE_LDCONFIG=	yes

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DEASTL_BUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		cd test && ctest -C ${CMAKE_BUILD_TYPE}

benchmark: build
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DEASTL_BUILD_BENCHMARK=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		cd benchmark && ctest -C ${CMAKE_BUILD_TYPE}

.include <bsd.port.mk>
