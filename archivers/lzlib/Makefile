PORTNAME=	lzlib
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip/lzlib

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	In-memory LZMA compression and decompression library
WWW=		https://www.nongnu.org/lzip/lzlib.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CONFIGURE_ARGS=	--enable-shared
GNU_CONFIGURE=	yes
INFO=		lzlib
INSTALL_TARGET=	install-strip
MAKE_ARGS=	${MAKE_ENV}
USES=		gmake
USE_LDCONFIG=	yes

PLIST_FILES=	include/lzlib.h \
		lib/liblz.a \
		lib/liblz.so \
		lib/liblz.so.${PORTVERSION:R} \
		lib/liblz.so.${PORTVERSION}

.include <bsd.port.mk>
