# Created by: Alistair King <alistair@caida.org>
# $FreeBSD$

PORTNAME=	wandio
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://research.wand.net.nz/software/wandio/

MAINTAINER=	alistair@caida.org
COMMENT=	C library for compressed file I/O

LICENSE=	GPLv2

USES=		libtool
CONFIGURE_ARGS=	--disable-silent-rules
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ZLIB BZIP2 LZO LZMA HTTP
OPTIONS_DEFAULT=	ZLIB BZIP2 LZMA HTTP

ZLIB_DESC=	Read/write support for ZLIB (gz) compressed files
BZIP2_DESC=	Read/write support for BZIP2 (bz2) compressed files
LZO_DESC=	Write support for LZO compressed files
LZMA_DESC=	Read/write support for LZMA compressed files
HTTP_DESC=	Support for reading files over HTTP

ZLIB_CONFIGURE_WITH=	zlib
BZIP2_CONFIGURE_WITH=	bzip2
LZO_CONFIGURE_WITH=	lzo
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZMA_CONFIGURE_WITH=	lzma
HTTP_CONFIGURE_WITH=	http
HTTP_LIB_DEPENDS=	libcurl.so:ftp/curl

.include <bsd.port.mk>
