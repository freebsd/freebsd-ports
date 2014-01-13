# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	rtree
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Rtree-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	R-Tree Spatial Index For Python GIS

BUILD_DEPENDS+=	${LOCALBASE}/include/spatialindex/SpatialIndex.h:${PORTSDIR}/devel/spatialindex
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Rtree
PYDISTUTILS_NOEGGINFO=	yes
WRKSRC=			${WRKDIR}/${DISTNAME}

NO_STAGE=	yes
post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/setup.cfg

.include <bsd.port.mk>
