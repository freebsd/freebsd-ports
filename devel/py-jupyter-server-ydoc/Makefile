PORTNAME=	jupyter-server-ydoc
PORTVERSION=	2.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_server_ydoc-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Jupyter-server extension integrating collaborative shared models
WWW=		https://jupyterlab-realtime-collaboration.readthedocs.io/en/latest/ \
		https://github.com/jupyterlab/jupyter-collaboration/tree/main/projects/jupyter-server-ydoc \
		https://github.com/jupyterlab/jupyter-collaboration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.4.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.18.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-events>=0.11.0:devel/py-jupyter-events@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=2.15.0<3.0.0:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server-fileid>=0.7.0<1:devel/py-jupyter-server-fileid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-ydoc>=3.0.3<4.0.0:devel/py-jupyter-ydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrdt>=0:devel/py-pycrdt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrdt-websocket>=0.16.0<0.17.0:devel/py-pycrdt-websocket@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
