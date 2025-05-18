PORTNAME=	uvwasi
PORTVERSION=	0.0.21
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WASI syscall API built atop libuv
WWW=		https://github.com/nodejs/uvwasi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake:testing pathfix

CMAKE_OFF=	ASAN \
		CODE_COVERAGE \
		UVWASI_DEBUG_LOG \
		UVWASI_BUILD_TESTS
CMAKE_ON=	INSTALL_UVWASI
CMAKE_TESTING_ON=	UVWASI_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	nodejs

.include <bsd.port.mk>
