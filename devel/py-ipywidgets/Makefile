PORTNAME=	ipywidgets
PORTVERSION=	8.1.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Interactive HTML widgets for Jupyter notebooks and the IPython kernel
WWW=		https://ipywidgets.readthedocs.io

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}comm>=0.1.3:devel/py-comm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=6.1.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=4.2.0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.3.1:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}widgetsnbextension>=4.0.0:devel/py-widgetsnbextension@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-widgets>=3.0.0:devel/py-jupyterlab-widgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

.include <bsd.port.mk>
