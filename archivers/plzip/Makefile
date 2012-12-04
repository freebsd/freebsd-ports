# Created by: Albert Vernon <f3cun3c02@sneakemail.com>
# $FreeBSD$

PORTNAME=	plzip
PORTVERSION=	0.9
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Is a parallel, lossless data compressor based on the LZMA algorithm

BUILD_DEPENDS=	lzlib>=1.1:${PORTSDIR}/archivers/lzlib

PLIST_FILES=	bin/plzip

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	CXXFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN1=		plzip.1
INFO=		plzip

.include <bsd.port.mk>
