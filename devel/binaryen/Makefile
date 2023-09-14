PORTNAME=	binaryen
DISTVERSIONPREFIX=	version_
DISTVERSION=	115
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	9d79632c210a8c5002657ae87ff06c70ee109e8f.patch:-p1 #https://github.com/WebAssembly/binaryen/issues/5928

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Compiler infrastructure and toolchain library for WebAssembly
WWW=		https://github.com/WebAssembly/binaryen

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang cpe python:build
CPE_VENDOR=	webassembly
USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	TEST
OPTIONS_SUB=	yes

TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_GH_TUPLE=		google:googletest:e2239ee:googletest/third_party/googletest

do-test-TEST-on:
	binaryen-unittests

.include <bsd.port.mk>
