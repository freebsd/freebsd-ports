# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	rtree
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	devel science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Rtree-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	R-Tree Spatial Index For Python GIS

BUILD_DEPENDS+=	${LOCALBASE}/include/spatialindex/SpatialIndex.h:${PORTSDIR}/devel/spatialindex
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/setup.cfg

.include <bsd.port.mk>
