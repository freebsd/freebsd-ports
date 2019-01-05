# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pnglite
PORTVERSION=	0.1.17
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight PNG C library

LICENSE=	ZLIB

USES=		dos2unix zip
USE_LDCONFIG=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	include/pnglite.h lib/libpnglite.so

do-build:
	cd ${WRKSRC} && ${CC} -o libpnglite.so -shared ${CFLAGS} -fPIC ${LDFLAGS} -lz pnglite.c

do-install:
	${INSTALL_LIB} ${WRKSRC}/libpnglite.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/pnglite.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
