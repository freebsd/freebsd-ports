PORTNAME=	ut
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++20 micro/Unit Testing Framework
WWW=		https://boost-ext.github.io/ut/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	boost-ext

CMAKE_OFF=	BOOST_UT_ALLOW_CPM_USE \
		BOOST_UT_BUILD_TESTS \
		BOOST_UT_BUILD_EXAMPLES
CMAKE_ARGS=	-DFREEBSD_WRKSRC_cpm=${WRKSRC_cpm} \
		-DCURRENT_CPM_VERSION=0.38.7
CMAKE_TESTING_ON=	BOOST_UT_BUILD_TESTS # 7 tests fail, see https://github.com/boost-ext/ut/issues/600

PLIST_FILES=	include/ut-2.0.0/include/boost/ut.hpp \
		lib/cmake/ut-2.0.0/utConfig.cmake \
		lib/cmake/ut-2.0.0/utConfigVersion.cmake \
		lib/cmake/ut-2.0.0/utTargets.cmake

NO_ARCH=	yes

.include <bsd.port.mk>
