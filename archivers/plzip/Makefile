# Created by: Albert Vernon <f3cun3c02@sneakemail.com>

PORTNAME=	plzip
PORTVERSION=	1.9
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip/${PORTNAME}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Parallel, lossless data compressor based on the LZMA algorithm

LICENSE=	GPLv2

BUILD_DEPENDS=	lzlib>=1.1:archivers/lzlib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CXXFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALL_TARGET=	install-strip
INFO=		plzip

PLIST_FILES=	bin/plzip \
		man/man1/plzip.1.gz

.include <bsd.port.mk>
