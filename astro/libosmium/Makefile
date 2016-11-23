# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libosmium
PORTVERSION=	2.10.3
DISTVERSIONPREFIX=	v
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast and flexible C++ library for working with OpenStreetMap data

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libboost_regex.so:devel/boost-libs \
		libgeos.so:graphics/geos \
		libexpat.so:textproc/expat2
BUILD_DEPENDS=	sparsehash>=0:devel/sparsehash

USE_GITHUB=	yes
GH_ACCOUNT=	osmcode

USES=		cmake compiler:c++11-lib
CMAKE_ARGS=	-DBUILD_EXAMPLES:BOOL=OFF

# though it build tests, the library itself it header-only
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	TEST DOCS
OPTIONS_DEFAULT=	TEST
TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	BUILD_TESTING

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
