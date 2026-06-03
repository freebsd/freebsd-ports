PORTNAME=	uvwasi
PORTVERSION=	0.0.23
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WASI syscall API built atop libuv
WWW=		https://github.com/nodejs/uvwasi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake:testing

CMAKE_OFF=	ASAN \
		BUILD_TESTING \
		CODE_COVERAGE \
		UVWASI_DEBUG_LOG
CMAKE_ON=	INSTALL_UVWASI

USE_GITHUB=	yes
GH_ACCOUNT=	nodejs

.include <bsd.port.mk>
