# New ports collection makefile for:	isreal
# Date created:				Mar 31, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	isreal
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	markp
EXTRACT_SUFX=	.tar

MAINTAINER=	markp@FreeBSD.org
COMMENT=	An image classification utility

USE_XLIB=	yes
USE_GNOME=	imlib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/isreal ${PREFIX}/bin

.include <bsd.port.mk>
