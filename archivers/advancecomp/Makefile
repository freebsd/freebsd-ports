# Created by: Radim Kolar

PORTNAME=	advancecomp
PORTVERSION=	1.23
CATEGORIES=	archivers
MASTER_SITES=	SF/advancemame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recompression utilities for .ZIP, .PNG, .MNG, and .GZ files

LICENSE=	GPLv3

LIB_DEPENDS=	libzopfli.so:archivers/zopfli

GNU_CONFIGURE=	yes
MAKE_ARGS=	zopfli_SOURCES="" am__objects_3=""
CPPFLAGS+=	-I${LOCALBASE}/include/zopfli
LDFLAGS+=	-L${LOCALBASE}/lib -lzopfli

.include <bsd.port.mk>
