# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.14.1
CATEGORIES=	graphics python
MASTER_SITES=	https://github.com/pygobject/pycairo/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 2 bindings for Cairo

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL-2.1
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING-MPL-1.1

PORTSCOUT=	limitw:1,even

USES=		gnome pkgconfig python:2
USE_PYTHON=	distutils
USE_GNOME=	cairo

PLIST_SUB=	PORTVER=${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cairo/_cairo.so

.include <bsd.port.mk>
