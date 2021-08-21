PORTNAME=	rapidfuzz-cpp
PORTVERSION=	g20210820
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rapid fuzzy string matching in C++ using the levenshtein distance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake:testing compiler:c++11-lib

CMAKE_TESTING_ON=	BUILD_TESTS # tests care broken because they expect yet unreleased catch-3.0.0 which is currently a preview version.

USE_GITHUB=	yes
GH_ACCOUNT=	maxbachmann
GH_TAGNAME=	47df6f7

NO_ARCH=	yes

.include <bsd.port.mk>
