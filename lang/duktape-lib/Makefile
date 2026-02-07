PORTNAME=	duktape
DISTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	https://github.com/svaarala/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://duktape.org/
PKGNAMESUFFIX=	-lib

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Embeddable Javascript engine (shared lib)
WWW=		https://duktape.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake tar:xz
USE_LDCONFIG=	yes

MAKEFILE=	Makefile.sharedlibrary
MAKE_ARGS=	INSTALL_PREFIX=${PREFIX}

MAJOR=	207
MINOR=	20700

PLIST_FILES=	include/duk_config.h \
		include/duktape.h \
		lib/libduktape.so \
		lib/libduktape.so.${MAJOR} \
		lib/libduktape.so.${MAJOR}.${MINOR} \
		libdata/pkgconfig/duktape.pc

do-install:
	${INSTALL_DATA} ${WRKSRC}/duktape.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_LIB} ${WRKSRC}/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib/libduktape.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}
	${INSTALL_DATA} ${WRKSRC}/src/duk_config.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/duktape.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
