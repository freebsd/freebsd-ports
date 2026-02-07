PORTNAME=	semver
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-rc
CATEGORIES=	devel

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Semantic Versioning for modern C++
WWW=		https://github.com/Neargye/semver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	Neargye

CMAKE_OFF=		SEMVER_OPT_BUILD_EXAMPLES \
			SEMVER_OPT_BUILD_TESTS
CMAKE_TESTING_ON=	SEMVER_OPT_BUILD_TESTS

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/semver.hpp \
		lib/cmake/semver/semverConfig.cmake \
		lib/cmake/semver/semverConfigVersion.cmake

.include <bsd.port.mk>
