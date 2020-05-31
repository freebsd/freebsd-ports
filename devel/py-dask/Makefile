# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dask
PORTVERSION=	2.17.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parallel PyData with Task Scheduling

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ARRAY BAG DATAFRAME DELAYED DIAGNOSTICS
ARRAY_DESC=	Subset of the NumPy ndarray interface
BAG_DESC=	Implements operations on collections of generic Python objects
DATAFRAME_DESC=	Composed of many smaller Pandas DataFrames
DELAYED_DESC=	Parallelize custom algorithms which do not fit into high-level abstractions
DIAGNOSTICS_DESC=	Profile and inspect parallel codes

ARRAY_RUN_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}toolz>=0.8.2:devel/py-toolz@${PY_FLAVOR}
BAG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>=0.2.2:devel/py-cloudpickle@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fsspec>=0.6.0:devel/py-fsspec@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}partd>=0.3.10:databases/py-partd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}toolz>=0.8.2:devel/py-toolz@${PY_FLAVOR}
DATAFRAME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>=0.6.0:devel/py-fsspec@${PY_FLAVOR} \
			${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}pandas>=0.23.0:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}partd>=0.3.10:databases/py-partd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}toolz>=0.8.2:devel/py-toolz@${PY_FLAVOR}
DELAYED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>=0.2.2:devel/py-cloudpickle@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}toolz>=0.8.2:devel/py-toolz@${PY_FLAVOR}
DIAGNOSTICS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}bokeh>=1.0.0:www/py-bokeh@${PY_FLAVOR}

.include <bsd.port.mk>
