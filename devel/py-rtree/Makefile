# Created by: wenheping@gmail.com

PORTNAME=	rtree
PORTVERSION=	0.9.7
CATEGORIES=	devel science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Rtree-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	R-Tree Spatial Index For Python GIS

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/spatialindex/SpatialIndex.h:devel/spatialindex \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.29.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/include/spatialindex/SpatialIndex.h:devel/spatialindex

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/setup.cfg

.include <bsd.port.mk>
