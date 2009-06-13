# Ports collection makefile for:	py-rtree
# Date created:			16 June, 2008
# Whom:				wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	rtree
PORTVERSION=	0.4.3
CATEGORIES=	devel science python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}source/R/Rtree/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Rtree-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	R-Tree Spatial Index For Python GIS

BUILD_DEPENDS+=	${LOCALBASE}/include/spatialindex/SpatialIndex.h:${PORTSDIR}/devel/spatialindex
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Rtree
PYDISTUTILS_NOEGGINFO=	yes
PYEASYINSTALL_ARCHDEP=	yes
WRKSRC=			${WRKDIR}/${DISTNAME}

post-extract:
	${REINPLACE_CMD} -e 's#/tmp/lasjunk#${LOCALBASE}#g' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
