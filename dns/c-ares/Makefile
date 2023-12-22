PORTNAME=	c-ares
DISTVERSION=	1.24.0
CATEGORIES=	dns
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/cares-${DISTVERSION:S/./_/g}/ \
		https://c-ares.org/download/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	7dd384a99cc385e408e64c3e0af4e0e2136ed034.patch:-p1

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Asynchronous DNS resolver library
WWW=		https://c-ares.haxx.se/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++11-lang pathfix
USE_LDCONFIG=	yes

CONFLICTS=	py*-ripe.atlas.tools

CMAKE_ARGS=		-DCMAKE_INSTALL_MANDIR:PATH=${MANPREFIX}/man

OPTIONS_DEFINE=		TEST

TEST_BUILD_DEPENDS=	googletest>0:devel/googletest
TEST_USES=		compiler:c++14-lang localbase:ldflags
TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	CARES_BUILD_TESTS

post-patch:
	@${REINPLACE_CMD} -e 's|ares-test-live.cc||g' \
		${PATCH_WRKSRC}/test/Makefile.inc

.include <bsd.port.mk>
