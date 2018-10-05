# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libb2
PORTVERSION=	0.98
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	mm@FreeBSD.org
COMMENT=	C library providing BLAKE2b, BLAKE2s, BLAKE2bp, BLAKE2sp

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	BLAKE2
GNU_CONFIGURE=	yes

PLIST_FILES=	include/blake2.h \
		lib/libb2.a \
		lib/libb2.so \
		lib/libb2.so.1 \
		lib/libb2.so.1.0.3

.include <bsd.port.mk>
