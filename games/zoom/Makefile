# New ports collection makefile for:	zoom
# Date created:				May 07 2003
# Whom:					Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	zoom
PORTVERSION=	1.0.1a
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.logicalshift.demon.co.uk/unix/${PORTNAME}/
DISTFILES=	${PORTNAME}-1.0.1.tar.gz

PATCHFILES=	zoom-1.0.1-1.0.1a.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	Jan.Stocker@t-online.de
COMMENT=	Z-Interpreter for X with full V6 support

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_PERL5=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-extract:
	${MV} ${WRKDIR}/${PORTNAME}-1.0.1 ${WRKSRC}

.include <bsd.port.mk>
