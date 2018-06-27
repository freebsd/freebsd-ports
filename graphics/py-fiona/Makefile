# $FreeBSD$

PORTNAME=	Fiona
DISTVERSION=	1.7.12
#DISTVERSIONSUFFIX=	.post2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	OGR's neat and nimble API for Python programmers

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cligj>=0.4:devel/py-cligj@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>0:devel/py-click-plugins@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}munch>0:devel/py-munch@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>0:devel/py-shapely@${FLAVOR} \
		${PY_ENUM34}
LIB_DEPENDS+=	libgdal.so:graphics/gdal

USES=		python
USE_PYTHON=	autoplist distutils cython

.include <bsd.port.mk>
