PORTNAME=	eastl
DISTVERSION=	3.21.12-9
DISTVERSIONSUFFIX=	-g089eb20
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronic Arts Standard Template Library
WWW=		https://github.com/electronicarts/EASTL

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		aarch64 riscv64
NOT_FOR_ARCHS_REASON=	test/packages/EABase/include/Common/EABase/config/eaplatform.h:436:4: error: Unknown processor

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	electronicarts
GH_PROJECT=	${PORTNAME:tu}
GH_TUPLE=	electronicarts:EAAssert:e5e1812:EAAssert/test/packages/EAAssert \
		electronicarts:EABase:521cb05:EABase/test/packages/EABase \
		electronicarts:EAMain:24ca8bf:EAMain/test/packages/EAMain \
		electronicarts:EAStdC:8dc9e31:EAStdC/test/packages/EAStdC \
		electronicarts:EATest:a59b372:EATest/test/packages/EATest \
		electronicarts:EAThread:e4367a3:EAThread/test/packages/EAThread

CMAKE_ON=	BUILD_SHARED_LIBS

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
