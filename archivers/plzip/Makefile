# Created by: Albert Vernon <f3cun3c02@sneakemail.com>
# $FreeBSD$

PORTNAME=	plzip
PORTVERSION=	1.5
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip/${PORTNAME}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Parallel, lossless data compressor based on the LZMA algorithm

BUILD_DEPENDS=	lzlib>=1.1:archivers/lzlib

PLIST_FILES=	bin/plzip \
		man/man1/plzip.1.gz

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CXXFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INFO=		plzip

.include <bsd.port.mk>
