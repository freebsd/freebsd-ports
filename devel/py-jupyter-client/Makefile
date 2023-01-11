PORTNAME=	jupyter-client
PORTVERSION=	7.4.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_client-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Jupyter protocol implementation and client libraries
WWW=		https://jupyter.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}entrypoints>=0:devel/py-entrypoints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=4.9.2:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=1.5.4:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.2:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=23.0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.2:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codecov>=0:devel/py-codecov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=6.12:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.18:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils pytest # 1 test fails, see https://github.com/jupyter/jupyter_client/issues/855

NO_ARCH=	yes

# upstream stopped providing setup.py
post-patch:
	@${ECHO_CMD} 'import setuptools; setuptools.setup()' > ${WRKSRC}/setup.py

.include <bsd.port.mk>
