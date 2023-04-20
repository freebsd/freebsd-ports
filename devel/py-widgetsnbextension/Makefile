PORTNAME=	widgetsnbextension
PORTVERSION=	4.0.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	IPython HTML widgets for Jupyter Notebook
WWW=		https://pypi.org/project/widgetsnbextension/

BUILD_DEPENDS=	npm>=0:www/npm \
		${PYTHON_PKGNAMEPREFIX}jupyter-packaging>0:devel/py-jupyter-packaging@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
