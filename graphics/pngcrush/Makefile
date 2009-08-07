# New ports collection makefile for:	pngcrush
# Date created:				07 December 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pngcrush
PORTVERSION=	1.7.0
CATEGORIES=	graphics
MASTER_SITES=	SF/pmt

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An optimizer for PNG files

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}"
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/pngcrush

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin/pngcrush

.include <bsd.port.mk>
