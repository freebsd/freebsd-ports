# New ports collection makefile for:	py-gobject
# Date created:				10 January 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	gobject
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/pygobject/2.8
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GObject

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

CONFLICTS=	py*-gtk-[0-9]*

.include <bsd.port.mk>
