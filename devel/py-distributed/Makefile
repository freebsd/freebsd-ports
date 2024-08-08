PORTNAME=	distributed
PORTVERSION=	2024.7.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Distributed scheduler for Dask
WWW=		https://distributed.dask.org/en/stable/ \
		https://github.com/dask/distributed

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=62.6:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}versioneer>=0.29:devel/py-versioneer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>=1.5.0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dask>=${PORTVERSION}<${PORTVERSION}_99:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}locket>=1.0.0:devel/py-locket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.7.2:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.0.5:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tblib>=1.6.0:devel/py-tblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>=0.10.0:devel/py-toolz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.0.4:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.24.3,1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zict>=3.0.0:devel/py-zict@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
