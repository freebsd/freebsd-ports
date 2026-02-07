PORTNAME=	cctz
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4
CATEGORIES=	devel

PATCH_SITES=	https://github.com/google/cctz/commit/
PATCHFILES=	64d12062183e2fa01f8c0127c4b9f91afaeee46c.patch:-p1

MAINTAINER=	z7dr6ut7gs@snkmail.com
COMMENT=	C++ library for handling dates, times, and time zones
WWW=		https://github.com/google/cctz

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	benchmark>0:devel/benchmark \
		googletest>0:devel/googletest

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	google

PORTDOCS=	README.md

CMAKE_OFF=	BUILD_EXAMPLES \
		BUILD_TESTING \
		BUILD_TOOLS
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DVERSION=${DISTVERSION} -DSOVERSION=${DISTVERSION:R}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
