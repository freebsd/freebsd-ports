PORTNAME=	plzip
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip/${PORTNAME}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Parallel, lossless data compressor based on the LZMA algorithm
WWW=		https://www.nongnu.org/lzip/plzip.html

LICENSE=	GPLv2

BUILD_DEPENDS=	lzlib>=1.1:archivers/lzlib

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	CXXFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALL_TARGET=	install-strip
INFO=		plzip

PLIST_FILES=	bin/plzip \
		share/man/man1/plzip.1.gz

.include <bsd.port.mk>
