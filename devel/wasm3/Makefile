PORTNAME=	wasm3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	The fastest WebAssembly interpreter, and the most universal runtime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake:insource cpe localbase:ldflags
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	wasm3
GH_PROJECT=	wasm3
GH_TUPLE+=	vshymanskyy:uvwasi:b063d686848:uvwasi/_deps/uvwasi-src

PLIST_FILES=	bin/wasm3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
