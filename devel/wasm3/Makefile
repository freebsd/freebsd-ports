PORTNAME=	wasm3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	High performance WebAssembly interpreter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake:insource cpe localbase:ldflags
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_TUPLE=	vshymanskyy:uvwasi:b063d686848:uvwasi/_deps/uvwasi-src

CMAKE_OFF=	BUILD_NATIVE

PLIST_FILES=	bin/wasm3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
