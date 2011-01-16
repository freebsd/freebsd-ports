# New ports collection makefile for:	plzip
# Date created:		2010-05-22
# Whom:			Albert Vernon <f3cun3c02@sneakemail.com>
#
# $FreeBSD$
#

PORTNAME=	plzip
PORTVERSION=	0.7
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip

MAINTAINER=	f3cun3c02@sneakemail.com
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
