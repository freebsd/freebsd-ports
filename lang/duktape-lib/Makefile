PORTNAME=	duktape
DISTVERSION=	2.6.0
CATEGORIES=	lang devel
MASTER_SITES=	https://duktape.org/
PKGNAMESUFFIX=	-lib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embeddable Javascript engine (shared lib)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake tar:xz
USE_LDCONFIG=	yes

MAKEFILE=	Makefile.sharedlibrary

MAJOR=	206
MINOR=	20600

PLIST_FILES=	include/duk_config.h \
		include/duktape.h \
		lib/libduktape.so \
		lib/libduktape.so.${MAJOR} \
		lib/libduktape.so.${MAJOR}.${MINOR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/duktape.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/duk_config.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib/libduktape.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}

.include <bsd.port.mk>
