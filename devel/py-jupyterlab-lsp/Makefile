PORTNAME=	jupyterlab-lsp
PORTVERSION=	5.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Coding assistance for JupyterLab with Language Server Protocol
WWW=		https://github.com/jupyter-lsp/jupyterlab-lsp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-lsp>=2.0.0:devel/py-jupyter-lsp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.1.0<5.0.0:devel/py-jupyterlab@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-extract:
	@${RM} ${WRKSRC}/jupyterlab_lsp/labextensions/@jupyter-lsp/jupyterlab-lsp/schemas/@jupyter-lsp/jupyterlab-lsp/package.json.orig

.include <bsd.port.mk>
