# New ports collection makefile for:	py-orbit2
# Date created:				04 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	orbit
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/pyorbit/2.0
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyorbit-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for ORBit2

CONFLICTS=	py*-omniorb*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack orbit2
USE_PYTHON=	yes
USE_LIBTOOL=	yes

.include <bsd.port.mk>
