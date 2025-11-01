PORTNAME=	dask-histogram
PORTVERSION=	2025.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dask_histogram-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Histogramming with Dask
WWW=		https://dask-histogram.readthedocs.io/en/stable/ \
		https://github.com/dask-contrib/dask-histogram

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.8.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-histogram>=1.3.2:misc/py-boost-histogram@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=2021.03.0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask-awkward>=2025:devel/py-dask-awkward@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
