# New ports collection makefile for:	glitz
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#   $MCom: ports/graphics/glitz/Makefile,v 1.8 2006/09/10 00:51:10 mezz Exp $
#

PORTNAME=	glitz
PORTVERSION=	0.5.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL image compositing library

USE_GL=		yes
USE_XORG=	xt
USE_GNOME=	pkgconfig gnometarget gnomehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
