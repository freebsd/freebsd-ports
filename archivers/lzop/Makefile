PORTNAME=	lzop
DISTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/ \
		LOCAL/mandree

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Fast file compressor similar to gzip, using the LZO library
WWW=		https://www.lzop.org/

LICENSE=	GPLv2+

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
