PORTNAME=	simpleini
PORTVERSION=	4.19
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ library providing a simple API to INI-style configuration files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	brofield
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*

PLIST_FILES=	include/SimpleIni.h

OPTIONS_DEFINE=	TEST DOCS

TEST_USES=	pkgconfig
TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest

do-install:
	${INSTALL_DATA} ${WRKSRC}/SimpleIni.h ${STAGEDIR}${PREFIX}/include

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

do-test-TEST-on:
	cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${TEST_ENV} \
		${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} test

.include <bsd.port.mk>
