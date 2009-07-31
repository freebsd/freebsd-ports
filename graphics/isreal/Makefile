# New ports collection makefile for:	isreal
# Date created:				Mar 31, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#    $MCom: ports/graphics/isreal/Makefile,v 1.1 2006/10/04 13:20:38 ahze Exp $

PORTNAME=	isreal
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	markp
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image classification utility

PLIST_FILES=	bin/isreal
USE_GNOME=	imlib
CFLAGS:=	${CFLAGS} -I${LOCALBASE}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/isreal ${PREFIX}/bin

.include <bsd.port.mk>
