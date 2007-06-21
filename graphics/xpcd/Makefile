# New ports collection makefile for:	xpcd
# Date created:		27 October 2001
# Whom:			Juha Ylitalo
#
# $FreeBSD$
#

PORTNAME=	xpcd
PORTVERSION=	2.09
PORTREVISION=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://dl.bytesex.org/releases/xpcd/

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	PhotoCD tool collection

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		pcd.2:${PORTSDIR}/graphics/libpcd

# USE_IMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
USE_X_PREFIX=	yes
MAN1=		pcdtoppm.1 pcdview.1 xpcd.1

DEPRECATED=		is an abandoned project and might be vulnerable
FORBIDDEN=		is an abandoned project and might be vulnerable
EXPIRATION_DATE=	2007-07-21

.include <bsd.port.mk>
