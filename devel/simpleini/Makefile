PORTNAME=	simpleini
DISTVERSIONPREFIX=	v
DISTVERSION=	4.24
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ library providing a simple API to INI-style configuration files
WWW=		https://github.com/brofield/simpleini

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	brofield
NO_ARCH=	yes
CMAKE_ON=	SIMPLEINI_USE_SYSTEM_GTEST
CMAKE_OFF=	SIMPLEINI_BUILD_EXAMPLES

PORTDOCS=	*

OPTIONS_DEFINE=	TEST DOCS

TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest
TEST_USES=		cmake:testing
TEST_USES_OFF=		cmake
TEST_CMAKE_BOOL=	SIMPLEINI_BUILD_TESTS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
