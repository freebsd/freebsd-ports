# New ports collection makefile for:	imagesort
# Date created:			Apr 10, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	imagesort
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/viewers/X

MAINTAINER=	mark@kyne.com.au

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imagesort ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/imagesort
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/imagesort
	${INSTALL_DATA} ${WRKSRC}/imagesortrc.sample ${PREFIX}/share/doc/imagesort
.endif

.include <bsd.port.mk>
