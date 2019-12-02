# $FreeBSD$

PORTNAME=	duktape
DISTVERSION=	2.5.0
CATEGORIES=	lang devel
MASTER_SITES=	https://duktape.org/
PKGNAMESUFFIX=	-lib

MAINTAINER=	alfix86@gmail.com
COMMENT=	Embeddable Javascript engine (shared lib)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake tar:xz
USE_LDCONFIG=	yes

MAKE_ARGS+=	CC=${CC}
MAKEFILE=	Makefile.sharedlibrary

MAJOR=	205
MINOR=	20500

PLIST_FILES=	include/duk_config.h \
		include/duktape.h \
		lib/libduktape.so \
		lib/libduktape.so.${MAJOR} \
		lib/libduktape.so.${MAJOR}.${MINOR} \
		lib/libduktaped.so \
		lib/libduktaped.so.${MAJOR} \
		lib/libduktaped.so.${MAJOR}.${MINOR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/duktape.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/duk_config.h ${STAGEDIR}${PREFIX}/include
.for l in libduktape.so libduktaped.so
	${INSTALL_LIB} ${WRKSRC}/${l}.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/${l}.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib/${l}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${l}.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib/${l}.${MAJOR}
.endfor

.include <bsd.port.mk>
