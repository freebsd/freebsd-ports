PORTNAME=	dask-expr
PORTVERSION=	1.0.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High Level Expressions for Dask
WWW=		https://github.com/dask/dask-expr

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}versioneer>=0.28:devel/py-versioneer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=62.6:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dask>=2024.3.1:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=7.0.0:databases/py-pyarrow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
