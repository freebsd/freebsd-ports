# New ports collection makefile for:	pixmap
# Date created:		19 February 1995
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	pixmap
PORTVERSION=	2.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/pixmap
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		${WRKDIR}/pixmap
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		pixmap.1

.include <bsd.port.pre.mk>
.if ${XFREE86_VERSION} == 4 # requires rgb.txt
BUILD_DEPENDS=	xrdb:${PORTSDIR}/x11/XFree86-4-clients
.endif

.include <bsd.port.post.mk>
