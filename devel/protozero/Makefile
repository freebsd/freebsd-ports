PORTNAME=	protozero
PORTVERSION=	1.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Minimalist protocol buffer decoder and encoder in C++
WWW=		https://github.com/mapbox/protozero

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	mapbox

USES=		cmake compiler:c++17-lang
CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
TEST_TARGET=	test
NO_ARCH=	yes  # header only library

PORTDOCS=	CHANGELOG.md README.md UPGRADING.md

OPTIONS_DEFINE=		DOCS TEST
OPTIONS_DEFAULT=	TEST  # no additional runtime reps
TEST_DESC=		Enable additional tests, requires protobuf at build time
TEST_BUILD_DEPENDS=	protoc:devel/protobuf

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
