PORTNAME=	duktape
DISTVERSION=	2.6.0
PORTREVISION=	1
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
		lib/libduktape.so.${MAJOR}.${MINOR} \
		libdata/pkgconfig/duktape.pc

SUB_FILES=	duktape.pc
SUB_LIST=	PORTVERSION=${DISTVERSION} \
		DESCRIPTION="${COMMENT}" \
		URL="${MASTER_SITES}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/duktape.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/duk_config.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib/libduktape.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}.${MINOR} ${STAGEDIR}${PREFIX}/lib/libduktape.so.${MAJOR}
	${INSTALL_DATA} ${WRKDIR}/duktape.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
