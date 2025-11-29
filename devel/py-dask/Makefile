PORTNAME=	dask
PORTVERSION=	2025.11.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parallel PyData with Task Scheduling
WWW=		https://dask.org/ \
		https://github.com/dask/dask

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=62.6:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>=3.0.0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=2021.09.0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}partd>=1.4.0:databases/py-partd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>=0.10.0:devel/py-toolz@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>=0:devel/py-pre-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CPE_VENDOR=	anaconda

OPTIONS_DEFINE=	ARRAY DATAFRAME DIAGNOSTICS
OPTIONS_DEFAULT=DATAFRAME
ARRAY_DESC=	Subset of the NumPy ndarray interface
DATAFRAME_DESC=	Composed of many smaller Pandas DataFrames
DATAFRAME_IMPLIES=	ARRAY
DIAGNOSTICS_DESC=	Profile and inspect parallel codes

ARRAY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.24,1:math/py-numpy@${PY_FLAVOR}
DATAFRAME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=2.0,1:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyarrow>=14.0.1:databases/py-pyarrow@${PY_FLAVOR}
DIAGNOSTICS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}bokeh>=3.1.0:www/py-bokeh@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.3:devel/py-Jinja2@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.13.0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
