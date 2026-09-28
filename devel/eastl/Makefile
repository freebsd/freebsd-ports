PORTNAME=	eastl
DISTVERSION=	3.27.01
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronic Arts Standard Template Library
WWW=		https://github.com/electronicarts/EASTL

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

#NOT_FOR_ARCHS=		aarch64 riscv64
#NOT_FOR_ARCHS_REASON=	EABase/include/Common/EABase/config/eaplatform.h:436:4: error: Unknown processor

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

USE_GITHUB=	yes
GH_ACCOUNT=	electronicarts
GH_PROJECT=	${PORTNAME:tu}
GH_TUPLE=	electronicarts:EAAssert:e5e181255de2e883dd1f987c78ccc42ac81d3bca:EAAssert/test/packages/EAAssert \
		electronicarts:EABase:0699a15efdfd20b6cecf02153bfa5663decb653c:EABase/EABase \
		electronicarts:EAMain:24ca8bf09e6b47b860286fc2f4c832f4009273d1:EAMain/test/packages/EAMain \
		electronicarts:EAStdC:fbcc34e89c63636054334888f3a5bd7ac2fd4b76:EAStdC/test/packages/EAStdC \
		electronicarts:EATest:a59b372fc9cba517283ad6d060d2ab96e0ba34ac:EATest/test/packages/EATest \
		electronicarts:EAThread:f3c6c54d19699639a5edcf5237ea8b71aca6842c:EAThread/test/packages/EAThread

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM:STRING=3.5 # CMake 4 compatibility, see https://github.com/electronicarts/EASTL/issues/597

CXXFLAGS+=	-isystem ${WRKSRC}/EABase/include/Common

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
