# New ports collection makefile for:	zoom
# Date created:				May 07 2003
# Whom:					Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	zoom
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.logicalshift.demon.co.uk/unix/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	Jan.Stocker@t-online.de
COMMENT=	Z-Interpreter for X with full V6 support

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAKE_ENV=	${CONFIGURE_ENV}

.include <bsd.port.mk>
