PORTNAME=	spirv-headers
DISTVERSIONPREFIX=	vulkan-sdk-
DISTVERSION=	1.4.363.0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Machine-readable files for the SPIR-V Registry
WWW=		https://github.com/KhronosGroup/SPIRV-Headers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Headers

CMAKE_OFF=		SPIRV_HEADERS_ENABLE_TESTS
CMAKE_TESTING_ON=	SPIRV_HEADERS_ENABLE_TESTS
CMAKE_TESTING_TARGET=	# empty

NO_ARCH=	yes

post-test: # tests are not registered with ctest
	@cd ${BUILD_WRKSRC}/tests && \
		./spirv_headers_simple_test && \
		./spirv_headers_simple_test_cpp11 && \
		./spirv_headers_simple_test_c && \
		${ECHO_MSG} "3 test programs passed, 0 failed"

# tests as of 1.4.363.0: 3 test programs passed, 0 failed

.include <bsd.port.mk>
