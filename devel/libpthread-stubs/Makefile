# New ports collection makefile for:   libpthread-stubs
# Date created:		24 January 2007
# Whom:			wahjava
#
# $FreeBSD$
#

PORTNAME=	libpthread-stubs
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	This library provides weak aliases for pthread functions

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CONFIGURE_ENV+=	LDFLAGS=-lpthread
.endif

.include <bsd.port.post.mk>
