# New ports collection makefile for:	pngcrush
# Date created:				07 December 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pngcrush
PORTVERSION=	1.7.24
CATEGORIES=	graphics
MASTER_SITES=	SF/pmt/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-nolib

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	An optimizer for PNG files

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_XZ=		yes
USE_GMAKE=	yes
CFLAGS+=	-DPNGCRUSH_COUNT_COLORS -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/pngcrush

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcrush ${PREFIX}/bin/pngcrush

.include <bsd.port.mk>
