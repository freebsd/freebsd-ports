# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	dask
PORTVERSION=	2021.6.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parallel PyData with Task Scheduling

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>=1.1.1:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=0.6.0:devel/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}partd>=0.3.10:databases/py-partd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>=0.8.2:devel/py-toolz@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ARRAY DATAFRAME DIAGNOSTICS
ARRAY_DESC=	Subset of the NumPy ndarray interface
DATAFRAME_DESC=	Composed of many smaller Pandas DataFrames
DIAGNOSTICS_DESC=	Profile and inspect parallel codes

ARRAY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16,1:math/py-numpy@${PY_FLAVOR} \
DATAFRAME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>=0.25.0,1:math/py-pandas@${PY_FLAVOR}
DIAGNOSTICS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}bokeh>=1.0.0:www/py-bokeh@${PY_FLAVOR}

.include <bsd.port.mk>
