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
COMMENT=	A pixmap editor based on XPM library

# requires rgb.txt
BUILD_DEPENDS=	xrdb:${X_CLIENTS_PORT}

WRKSRC=		${WRKDIR}/pixmap
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		pixmap.1

.include <bsd.port.mk>
