PORTNAME=	gpds
DISTVERSION=	1.5.0
CATEGORIES=	devel

MAINTAINER=	jbo@insane.engineer
COMMENT=	General purpose data serializer library written in modern C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to other architectures

RUN_DEPENDS=	spdlog>=1.9.0:devel/spdlog

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	simulton

CMAKE_OFF=	GPDS_BUILD_EXAMPLES GPDS_BUILD_TESTS
CMAKE_ON=	GPDS_FEATURE_SPDLOG

.include <bsd.port.mk>
