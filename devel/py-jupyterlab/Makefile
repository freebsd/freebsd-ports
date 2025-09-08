PORTNAME=	jupyterlab
PORTVERSION=	4.4.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyterlab/jupyterlab/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JupyterLab server extension
WWW=		https://jupyter.org/ \
		https://jupyterlab.readthedocs.io/en/latest/ \
		https://github.com/jupyterlab/jupyterlab

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.3.2:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.21.1:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async-lru>=1.0.0:devel/py-async-lru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.25.0<1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=6.5.0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=0:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-lsp>=2.0.0:devel/py-jupyter-lsp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=2.4.0<3:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-server>=2.27.1<3:devel/py-jupyterlab-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook-shim>=0.2:devel/py-notebook-shim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=41.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.2.0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.8.3:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
