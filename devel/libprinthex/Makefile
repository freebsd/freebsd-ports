PORTNAME=	libprinthex
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Print a hex dump with colored sections
WWW=		https://github.com/rstemmer/libprinthex

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CFLAGS+=	-fPIC

PLIST_FILES=	include/printhex.h \
		lib/libprinthex.so \
		lib/libprinthex.so.1 \
		lib/libprinthex.so.${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	rstemmer

do-build:
	@${CC} ${CFLAGS} -I${WRKSRC} -shared -Wl,-soname,libprinthex.so.1 ${WRKSRC}/printhex.c -o ${WRKSRC}/libprinthex.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/printhex.h ${STAGEDIR}${PREFIX}/include/printhex.h
	${INSTALL_LIB} ${WRKSRC}/libprinthex.so ${STAGEDIR}${PREFIX}/lib/libprinthex.so.${PORTVERSION}
	${LN} -s libprinthex.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libprinthex.so
	${LN} -s libprinthex.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libprinthex.so.1

.include <bsd.port.mk>
