PORTNAME=	rapidfuzz-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rapid fuzzy string matching in C++ using the levenshtein distance
WWW=		https://github.com/maxbachmann/rapidfuzz-cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake:testing compiler:c++11-lib

CMAKE_TESTING_ON=	RAPIDFUZZ_BUILD_TESTING # tests use downloaded catch3 instead of catch2 from ports
# tests fail to configure, see https://github.com/maxbachmann/rapidfuzz-cpp/issues/96

USE_GITHUB=	yes
GH_ACCOUNT=	maxbachmann

NO_ARCH=	yes

.include <bsd.port.mk>
