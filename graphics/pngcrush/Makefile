# New ports collection makefile for:	pngcrush
# Date created:				07 December 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pngcrush
PORTVERSION=	1.6.7
CATEGORIES=	graphics
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	pmt

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An optimizer for PNG files

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}"

PLIST_FILES=	bin/pngcrush

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin/pngcrush

.include <bsd.port.mk>
