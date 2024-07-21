PORTNAME=	dask-awkward
PORTVERSION=	2024.6.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dask_awkward-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Awkward Array meets Dask
WWW=		https://dask-awkward.readthedocs.io/en/stable/ \
		https://github.com/dask-contrib/dask-awkward

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.8.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awkward>=2.5.1:math/py-awkward@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=2023.04.0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.8.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	COMPLETE IO
COMPLETE_DESC=		Complete functionality
COMPLETE_IMPLIES=	IO
IO_DESC=		Aggregate metadata from data files

IO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyarrow>=0:databases/py-pyarrow@${PY_FLAVOR}

.include <bsd.port.mk>
