PORTNAME=	binaryen
DISTVERSIONPREFIX=	version_
DISTVERSION=	124
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Compiler infrastructure and toolchain library for WebAssembly
WWW=		https://github.com/WebAssembly/binaryen

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing cpe localbase:ldflags python:build
CPE_VENDOR=	webassembly
USE_GITHUB=	yes
GH_ACCOUNT=	WebAssembly
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=	# No internal target for running tests. Run via post-test.

post-test:
	${BUILD_WRKSRC}/bin/binaryen-unittests

.include <bsd.port.mk>
