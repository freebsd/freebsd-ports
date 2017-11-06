# Created by: will
# $FreeBSD$

PORTNAME=	lzop
DISTVERSION=	1.04
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/ \
		LOCAL/mandree

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Fast file compressor similar to gzip, using the LZO library

LICENSE=	GPLv2+

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
