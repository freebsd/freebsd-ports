PORTNAME=	jupyter-rfb
DISTVERSION=	1.0.2
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anywidget>0:devel/py-anywidget@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>=7.6.0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}simplejpeg>0:graphics/py-simplejpeg@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

NO_ARCH=	yes

# tests as of 1.0.2:
# Results (3.16s):
#          3 passed
#          2 warnings

.include <bsd.port.mk>
