# Created by: vanilla@
# $FreeBSD$

PORTNAME=	caf
PORTVERSION=	0.15.3
CATEGORIES=	devel

MAINTAINER=	vallentin@icir.org
COMMENT=	C++ actor framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

CXXFLAGS+=	-std=c++11 -Wextra -Wall -pedantic
LDFLAGS+=	-pthread
USES=		cmake:outsource compiler:c++11-lang
USE_LDCONFIG=	yes
TEST_TARGET=	test
USE_GITHUB=	yes
GH_ACCOUNT=	actor-framework
GH_PROJECT=	${GH_ACCOUNT}

OPTIONS_DEFINE=	DEBUG TEST STATIC
OPTIONS_RADIO=	LOG_LEVEL
OPTIONS_RADIO_LOG_LEVEL=	LOG_LEVEL_ERROR LOG_LEVEL_WARN LOG_LEVEL_INFO LOG_LEVEL_DEBUG LOG_LEVEL_TRACE
OPTIONS_DEFAULT=	TEST
OPTIONS_SUB=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

TEST_DESC=	Build with unit tests
STATIC_DESC=	Additionally build static version of library
LOG_LEVEL_ERROR=	Use log level ERROR for console output
LOG_LEVEL_WARN=	Use log level WARN for console output
LOG_LEVEL_INFO=	Use log level INFO for console output
LOG_LEVEL_DEBUG=	Use log level DEBUG for console output
LOG_LEVEL_TRACE=	Use log level TRACE for console output

# Until we cannot automatically disentangle examples from other binaries, we do
# not support an EXAMPLES option. We also disable a few components that are
# still quite experimental.
CMAKE_ARGS+=	-DCAF_NO_EXAMPLES:BOOL=yes -DCAF_NO_OPENCL:BOOL=yes

DEBUG_CMAKE_ON=	-DCAF_ENABLE_RUNTIME_CHECKS:BOOL=yes
STATIC_CMAKE_ON=	-DCAF_BUILD_STATIC:BOOL=yes
TEST_CMAKE_OFF=	-DCAF_NO_UNIT_TESTS:BOOL=yes
LOG_LEVEL_ERROR_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=0
LOG_LEVEL_WARN_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=1
LOG_LEVEL_INFO_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=2
LOG_LEVEL_DEBUG_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=3
LOG_LEVEL_TRACE_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=4

.include <bsd.port.mk>
