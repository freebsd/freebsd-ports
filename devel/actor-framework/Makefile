PORTNAME=	actor-framework
DISTVERSION=	0.19.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Source implementation of the Actor Model in C++
WWW=		https://www.actor-framework.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes

CMAKE_OFF=	CAF_ENABLE_TESTING
CMAKE_TESTING_ON=	CAF_ENABLE_TESTING # the decorator.sequencer testcase fails intermittently, see https://github.com/actor-framework/actor-framework/issues/1456

OPTIONS_DEFINE=	DEBUG
OPTIONS_RADIO=	LOG_LEVEL
OPTIONS_RADIO_LOG_LEVEL=	LOG_LEVEL_ERROR LOG_LEVEL_WARN LOG_LEVEL_INFO LOG_LEVEL_DEBUG LOG_LEVEL_TRACE

DEBUG_DESC=		Build with extra runtime assertions
DEBUG_CMAKE_BOOL=	CAF_ENABLE_RUNTIME_CHECKS

LOG_LEVEL_DEBUG_DESC=	Use log level DEBUG for console output
LOG_LEVEL_ERROR_DESC=	Use log level ERROR for console output
LOG_LEVEL_INFO_DESC=	Use log level INFO for console output
LOG_LEVEL_TRACE_DESC=	Use log level TRACE for console output
LOG_LEVEL_WARN_DESC=	Use log level WARN for console output

LOG_LEVEL_ERROR_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=ERROR
LOG_LEVEL_WARN_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=WARN
LOG_LEVEL_INFO_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=INFO
LOG_LEVEL_DEBUG_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=DEBUG
LOG_LEVEL_TRACE_CMAKE_ON=	-DCAF_LOG_LEVEL:STRING=TRACE

.include <bsd.port.mk>
