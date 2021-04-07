PORTNAME=	jupyterlab-widgets
DISTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyterlab_widgets-${DISTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	JupyterLab extension for Jupyter/IPython widgets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-packaging>0:devel/py-jupyter-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyterlab>=3.0.0:devel/py-jupyterlab@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

PYDISTUTILS_CONFIGUREARGS=	--skip-npm
PYDISTUTILS_BUILDARGS=		--skip-npm
PYDISTUTILS_INSTALLARGS=	--skip-npm

.include <bsd.port.mk>
