# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	rtree
PORTVERSION=	0.8.2
CATEGORIES=	devel science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Rtree-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	R-Tree Spatial Index For Python GIS

LICENSE=	LGPL21

BUILD_DEPENDS+=	${LOCALBASE}/include/spatialindex/SpatialIndex.h:devel/spatialindex
RUN_DEPENDS+=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/setup.cfg

.include <bsd.port.mk>
