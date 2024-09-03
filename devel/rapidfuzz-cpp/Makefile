PORTNAME=	rapidfuzz-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.5
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rapid fuzzy string matching in C++ using the levenshtein distance
WWW=		https://github.com/rapidfuzz/rapidfuzz-cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++17-lang

CMAKE_TESTING_ON=	RAPIDFUZZ_BUILD_TESTING

USE_GITHUB=	yes
GH_ACCOUNT=	rapidfuzz

NO_ARCH=	yes

.include <bsd.port.mk>
