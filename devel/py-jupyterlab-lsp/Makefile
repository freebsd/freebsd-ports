PORTNAME=	jupyterlab-lsp
PORTVERSION=	5.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Coding assistance for JupyterLab with Language Server Protocol
WWW=		https://github.com/jupyter-lsp/jupyterlab-lsp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-lsp>=2.0.0:devel/py-jupyter-lsp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.0.6<5.0.0a0:devel/py-jupyterlab@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-extract:
	@${RM} ${WRKSRC}/jupyterlab_lsp/labextensions/@jupyter-lsp/jupyterlab-lsp/schemas/@jupyter-lsp/jupyterlab-lsp/package.json.orig

.include <bsd.port.mk>
