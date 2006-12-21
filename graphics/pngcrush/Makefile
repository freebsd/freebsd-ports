# New ports collection makefile for:	pngcrush
# Date created:				07 December 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pngcrush
PORTVERSION=	1.6.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pmt

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	An optimizer for PNG files

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	Makefile.ext-zlib
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LIBS="-lz -lm" \
		ZINC="" ZLIB=""

PLIST_FILES=	bin/pngcrush

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush-zlib ${PREFIX}/bin/pngcrush

.include <bsd.port.mk>
