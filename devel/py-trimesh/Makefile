# $FreeBSD$

PORTNAME=	trimesh
PORTVERSION=	3.5.25
CATEGORIES=	devel cad python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Library for loading and using triangular meshes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

# This order of dependancies directly lifted from setup.py please do not change!
NEEDED_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyglet>0:graphics/py-pyglet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtree>0:devel/py-rtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svg_path>0:graphics/py-svg.path@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>0:devel/py-xxhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycollada>0:graphics/py-pycollada@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}triangle>0:math/py-triangle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>0:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-fcl>0:math/py-python-fcl@${PY_FLAVOR}
BUILD_DEPENDS=	${NEEDED_DEPENDS}
RUN_DEPENDS=	${NEEDED_DEPENDS}

USES=		compiler:c++11-lang python:3.5+

USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

.include <bsd.port.mk>
