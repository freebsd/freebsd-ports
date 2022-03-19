PORTNAME=	rapidfuzz-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rapid fuzzy string matching in C++ using the levenshtein distance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake:testing compiler:c++11-lib

CMAKE_TESTING_ON=	RAPIDFUZZ_BUILD_TESTING # tests are broken because they expect yet unreleased catch-3.0.0 which is currently a preview version.

USE_GITHUB=	yes
GH_ACCOUNT=	maxbachmann

NO_ARCH=	yes

.include <bsd.port.mk>
