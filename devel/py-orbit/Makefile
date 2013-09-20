# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/py-orbit/Makefile,v 1.1 2008/09/23 20:08:04 mezz Exp $

PORTNAME=	orbit
PORTVERSION=	2.24.0
CATEGORIES=	devel python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pyorbit/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyorbit-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for ORBit2

CONFLICTS=	py*-omniorb-[0-9]*

USES=		pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack orbit2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
ORBIT_CONFIG=	${LOCALBASE}/bin/orbit2-config

NO_STAGE=	yes
.include <bsd.port.mk>
