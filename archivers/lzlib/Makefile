PORTNAME=	lzlib
PORTVERSION=	1.13
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip/lzlib

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	In-memory LZMA compression and decompression library
WWW=		https://www.nongnu.org/lzip/lzlib.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ARGS=	${MAKE_ENV}
INFO=		lzlib

PLIST_FILES=	include/lzlib.h \
		lib/liblz.a

.include <bsd.port.mk>
