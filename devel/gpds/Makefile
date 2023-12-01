PORTNAME=	gpds
DISTVERSION=	1.8.1
CATEGORIES=	devel

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	General purpose data serializer library written in modern C++
WWW=		https://github.com/simulton/gpds

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake compiler:c++20-lang
USE_GITHUB=	yes
GH_ACCOUNT=	simulton

CMAKE_ON=	GPDS_BUILD_STATIC GPDS_BUILD_SHARED
CMAKE_OFF=	GPDS_BUILD_EXAMPLES GPDS_BUILD_TESTS

PLIST_SUB=	SOVERSION="${DISTVERSION}"

OPTIONS_DEFINE=		SPDLOG
OPTIONS_DEFAULT=	SPDLOG
OPTIONS_SUB=		yes

SPDLOG_DESC=		Enable (de)serialization interface for spdlog
SPDLOG_RUN_DEPENDS=	spdlog>=1.9.0:devel/spdlog
SPDLOG_CMAKE_BOOL=	GPDS_FEATURE_SPDLOG

.include <bsd.port.mk>
