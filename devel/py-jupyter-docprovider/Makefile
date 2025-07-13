PORTNAME=	jupyter-docprovider
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_docprovider-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JupyterLab/Jupyter Notebook 7+ extension integrating collaborative shared models
WWW=		https://jupyterlab-realtime-collaboration.readthedocs.io/en/latest/ \
		https://github.com/jupyterlab/jupyter-collaboration/tree/main/projects/jupyter-docprovider \
		https://github.com/jupyterlab/jupyter-collaboration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.5:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.4.0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.0.0:devel/py-jupyterlab@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
