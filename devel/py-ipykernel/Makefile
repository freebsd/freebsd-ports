PORTNAME=	ipykernel
PORTVERSION=	6.30.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/ipython/ipykernel/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	IPython Kernel for Jupyter
WWW=		https://ipython.org/ \
		https://ipykernel.readthedocs.io/en/stable/ \
		https://github.com/ipython/ipykernel

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.4:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=6:devel/py-jupyter-client@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}comm>=0.1.1:devel/py-comm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debugpy>=1.6.5:devel/py-debugpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.23.1:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=8.0.2:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=4.12:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib-inline>=0.1:math/py-matplotlib-inline@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=1.4:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.7:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=25:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.2:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5.4.0:devel/py-traitlets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
