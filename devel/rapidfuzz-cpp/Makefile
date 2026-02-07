PORTNAME=	rapidfuzz-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rapid fuzzy string matching in C++ using the levenshtein distance
WWW=		https://github.com/rapidfuzz/rapidfuzz-cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake:testing compiler:c++17-lang

CMAKE_TESTING_ON=	RAPIDFUZZ_BUILD_TESTING

USE_GITHUB=	yes
GH_ACCOUNT=	rapidfuzz

NO_ARCH=	yes

# tests as of 3.3.3: 100% tests passed, 0 tests failed out of 10

.include <bsd.port.mk>
