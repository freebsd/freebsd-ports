PORTNAME=	jupyter-collaboration
PORTVERSION=	2.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyterlab/jupyter-collaboration/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_collaboration-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JupyterLab Extension enabling Real-Time Collaboration
WWW=		https://jupyterlab-realtime-collaboration.readthedocs.io/en/latest/ \
		https://github.com/jupyterlab/jupyter-collaboration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.5:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>=0:devel/py-hatch-nodejs-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.4.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.18.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-events>=0.10.0:devel/py-jupyter-events@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=2.0.0<3.0.0:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server-fileid>=0.7.0<1:devel/py-jupyter-server-fileid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-ydoc>=2.0.0<3.0.0:devel/py-jupyter-ydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrdt>=0:devel/py-pycrdt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrdt-websocket>=0.14.0<0.15.0:devel/py-pycrdt-websocket@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-extract:
	@${RM} ${WRKSRC}/jupyter_collaboration/labextension/schemas/@jupyter/collaboration-extension/package.json.orig

.include <bsd.port.mk>
