# New ports collection makefile for:	isreal
# Date created:				Mar 31, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	isreal
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	markp
EXTRACT_SUFX=	.tar

MAINTAINER=	markp@FreeBSD.org

USE_XLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/isreal ${PREFIX}/bin

.include <bsd.port.mk>
