PORTNAME=	kassert
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Karlsruhe assertion library for C++
WWW=		https://kamping-site.github.io/kassert/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	kamping-site
GH_TUPLE=	jothepro:doxygen-awesome-css:v2.3.3:awesome

CMAKE_OFF=	KASSERT_BUILD_TESTS \
		KASSERT_USE_BUNDLED_GTEST
CMAKE_TESTING_ON=	KASSERT_BUILD_TESTS

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	doxygen>=1.9.0:devel/doxygen
DOCS_CMAKE_BOOL=	KASSERT_BUILD_DOCS
DOCS_ALL_TARGET=	all kassert_docs
DOCS_VARS_OFF=	no_build=yes

post-extract:
	${MKDIR} ${BUILD_WRKSRC}/_deps
	${RLN} ${WRKSRC_awesome} ${BUILD_WRKSRC}/_deps/doxygen-awesome-css-src

.include <bsd.port.mk>
