# Created by: Albert Vernon <f3cun3c02@sneakemail.com>
# $FreeBSD$

PORTNAME=	lzlib
PORTVERSION=	1.11
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip/lzlib

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	In-memory LZMA compression and decompression library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	include/lzlib.h \
		lib/liblz.a

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ARGS=	${MAKE_ENV}
INFO=		lzlib

.include <bsd.port.mk>
