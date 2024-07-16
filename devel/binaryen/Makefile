PORTNAME=	binaryen
DISTVERSIONPREFIX=	version_
DISTVERSION=	118
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Compiler infrastructure and toolchain library for WebAssembly
WWW=		https://github.com/WebAssembly/binaryen

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe python:build
CPE_VENDOR=	webassembly
USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	TEST
OPTIONS_SUB=	yes

TEST_LIB_DEPENDS=	libgtest.so:devel/googletest
TEST_USES=		localbase:ldflags
TEST_CMAKE_BOOL=	BUILD_TESTS

do-test-TEST-on:
	binaryen-unittests

.include <bsd.port.mk>
