PORTNAME=	jupyter-rfb
DISTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Remote Frame Buffer for Jupyter
WWW=		https://jupyter-rfb.readthedocs.io/en/stable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}jupyter-packaging>=0.7.9:devel/py-jupyter-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=3.0.0:devel/py-jupyterlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}simplejpeg>0:graphics/py-simplejpeg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>=7.6.0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-widgets>0:devel/py-jupyterlab-widgets@${PY_FLAVOR} \
		${PYNUMPY} # probably only one of pillow and simplejpeg is needed

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

NO_ARCH=	yes

.include <bsd.port.mk>
