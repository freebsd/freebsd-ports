PORTNAME=	c-ares
DISTVERSION=	1.33.0
CATEGORIES=	dns
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Asynchronous DNS resolver library
WWW=		https://c-ares.haxx.se/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake pathfix
USE_LDCONFIG=	yes

CONFLICTS=	py*-ripe.atlas.tools

OPTIONS_DEFINE=	STATIC TEST
OPTIONS_SUB=	yes

STATIC_CMAKE_BOOL=	CARES_STATIC

TEST_BUILD_DEPENDS=	googletest>0:devel/googletest
TEST_USES=		compiler:c++14-lang localbase:ldflags
TEST_CMAKE_BOOL=	CARES_BUILD_TESTS
TEST_TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's|ares-test-live.cc||g' \
		${PATCH_WRKSRC}/test/Makefile.inc

post-install-STATIC-on:
	@${RLN} libcares_static.a ${STAGEDIR}/${PREFIX}/lib/libcares.a

.include <bsd.port.mk>
