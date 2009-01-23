# New ports collection makefile for:	pixmap
# Date created:		19 February 1995
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	pixmap
PORTVERSION=	2.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/pixmap
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pixmap editor based on XPM library

# requires rgb.txt
BUILD_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb \
		showrgb:${PORTSDIR}/x11/rgb


WRKSRC=		${WRKDIR}/pixmap
USE_IMAKE=	yes
USE_XORG=	xpm xbitmaps x11 xaw xmu xt sm ice xext
MAN1=		pixmap.1

CFLAGS+=	-D_X_SENTINEL\(x\)= -D_X_ATTRIBUTE_PRINTF\(x,y\)=

.include <bsd.port.mk>
