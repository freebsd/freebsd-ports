# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pnglite
PORTVERSION=	0.1.17
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight PNG C library

LICENSE=	ZLIB

USES=		dos2unix zip
USE_LDCONFIG=	yes
SOVERSION=	0

LDFLAGS+=	-fPIC -Wl,-soname,libpnglite.so.${SOVERSION}

NO_WRKSUBDIR=	yes

PLIST_FILES=	include/pnglite.h lib/libpnglite.so lib/libpnglite.so.${SOVERSION}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -shared pnglite.c -o libpnglite.so.${SOVERSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/pnglite.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libpnglite.so.${SOVERSION} ${STAGEDIR}${PREFIX}/lib
	${LN} -s libpnglite.so.${SOVERSION} ${STAGEDIR}${PREFIX}/lib/libpnglite.so

.include <bsd.port.mk>
