PORTNAME=	expected
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	devel science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++11/14/17 std::expected with functional-style extensions
WWW=		https://tl.tartanllama.xyz/en/latest/ \
		https://github.com/TartanLlama/expected

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing localbase

USE_GITHUB=	yes
GH_ACCOUNT=	TartanLlama

CMAKE_OFF=	EXPECTED_BUILD_TESTS \
		FETCHCONTENT_FULLY_DISCONNECTED # need connected mode for tests to fetch a specific old version of catch2
CMAKE_TESTING_ON=	EXPECTED_BUILD_TESTS

PLIST_FILES=	include/tl/expected.hpp \
		share/cmake/tl-expected/tl-expected-config-version.cmake \
		share/cmake/tl-expected/tl-expected-config.cmake \
		share/cmake/tl-expected/tl-expected-targets.cmake

NO_ARCH=	yes

post-install: # workaround for https://github.com/TartanLlama/expected/issues/173
	@${REINPLACE_CMD} -i '' \
		-e 's/1\.0\.0/${PORTVERSION}/' \
		${STAGEDIR}${PREFIX}/share/cmake/tl-expected/tl-expected-config-version.cmake

# tests as of 1.2.0: 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
