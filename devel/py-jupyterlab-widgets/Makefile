PORTNAME=	jupyterlab-widgets
DISTVERSION=	3.0.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyterlab_widgets-${DISTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	JupyterLab extension for Jupyter/IPython widgets
WWW=		https://pypi.python.org/pypi/jupyterlab-widgets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-packaging>0:devel/py-jupyter-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyterlab>=3.0.0:devel/py-jupyterlab@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PYDISTUTILS_CONFIGUREARGS=	--skip-npm
PYDISTUTILS_BUILDARGS=		--skip-npm
PYDISTUTILS_INSTALLARGS=	--skip-npm

.include <bsd.port.mk>
