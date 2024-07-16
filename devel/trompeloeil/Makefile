PORTNAME=	trompeloeil
DISTVERSIONPREFIX=	v
DISTVERSION=	48
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header only C++14 mocking framework
WWW=		https://github.com/rollbear/trompeloeil

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

TEST_DEPENDS=	${LOCALBASE}/include/catch2/catch.hpp:devel/catch \
		criterion>0:devel/criterion

USES=		cmake:testing compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	rollbear

CMAKE_TESTING_ON=	TROMPELOEIL_BUILD_TESTS
CMAKE_TESTING_TARGET=	self_test thread_terror custom_recursive_mutex # see the README

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	@cd ${STAGEDIR}${DOCSDIR} && \
		${RM} LICENSE_1_0.txt && \
		${MV} docs/* . && \
		${RMDIR} docs

post-test: # run tests (tests fail to compile, see https://github.com/rollbear/trompeloeil/issues/322)
.for exe in ${CMAKE_TESTING_TARGET}
	${ECHO} "==> Running tests executable ${exe}"
	@cd ${TEST_WRKSRC} && test/${exe}
.endfor

.include <bsd.port.mk>
