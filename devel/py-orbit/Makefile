# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/py-orbit/Makefile,v 1.1 2008/09/23 20:08:04 mezz Exp $

PORTNAME=	orbit
PORTVERSION=	2.24.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	GNOME/sources/pyorbit/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyorbit-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for ORBit2

CONFLICTS=	py*-omniorb-[0-9]*

USES=		gmake libtool pathfix pkgconfig python:2.7 tar:bzip2
USE_GNOME=	orbit2
USE_PYTHON=	flavors
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
