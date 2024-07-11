PORTNAME=	simpleini
DISTVERSIONPREFIX=	v
DISTVERSION=	4.22
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ library providing a simple API to INI-style configuration files
WWW=		https://github.com/brofield/simpleini

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	brofield
NO_ARCH=	yes
CMAKE_ON=	SIMPLEINI_USE_SYSTEM_GTEST

PORTDOCS=	*

OPTIONS_DEFINE=	TEST DOCS

TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest

post-patch-TEST-off:
	@${REINPLACE_CMD} -e '/add_subdirectory(tests/ d' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
