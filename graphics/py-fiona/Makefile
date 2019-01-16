# $FreeBSD$

PORTNAME=	Fiona
DISTVERSION=	1.7.13
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	OGR's neat and nimble API for Python programmers

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cligj>=0.4:devel/py-cligj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-plugins>0:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}munch>0:devel/py-munch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>0:devel/py-shapely@${PY_FLAVOR} \
		${PY_ENUM34}
LIB_DEPENDS+=	libgdal.so:graphics/gdal

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist distutils cython

.include <bsd.port.mk>
