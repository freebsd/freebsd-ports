PORTNAME=	jupyter-collaboration
PORTVERSION=	4.1.1
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.4.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-collaboration-ui>=2.1.1<3:devel/py-jupyter-collaboration-ui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-docprovider>=2.1.1<3:devel/py-jupyter-docprovider@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server-ydoc>=2.1.1<3:devel/py-jupyter-server-ydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.4.0<5.0.0:devel/py-jupyterlab@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
