# New ports collection makefile for:	imagesort
# Date created:			Apr 10, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	imagesort
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/viewers/X

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A flexible X utility for managing many image files

USE_X_PREFIX=	yes
USE_GNOME=	imlib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imagesort ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/imagesort
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/imagesort
	${INSTALL_DATA} ${WRKSRC}/imagesortrc.sample ${PREFIX}/share/doc/imagesort
.endif

.include <bsd.port.mk>
