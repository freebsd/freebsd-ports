# New ports collection makefile for:	xpcd
# Date created:		27 October 2001
# Whom:			Juha Ylitalo
#
# $FreeBSD$
#

PORTNAME=	xpcd
PORTVERSION=	2.08
PORTREVISION=	2
CATEGORIES+=	graphics
MASTER_SITES=	http://bytesex.org/misc/

MAINTAINER?=	jylitalo@iki.fi
COMMENT?=	PhotoCD tool collection

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

# USE_IMAKE=	yes
CFLAGS+=        -I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS=	-L${LOCALBASE}/lib
USE_GMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
USE_X_PREFIX=	yes
MAN1=		pcdtoppm.1 pcdview.1 xpcd.1

.include <bsd.port.mk>
