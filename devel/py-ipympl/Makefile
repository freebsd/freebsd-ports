PORTNAME=	ipympl
DISTVERSION=	0.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Matplotlib Jupyter extension
WWW=		https://github.com/matplotlib/ipympl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.8.3:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>=0.3.2:devel/py-hatch-nodejs-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.0.0:devel/py-jupyterlab@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.5.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>0:devel/py-traitlets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

# The sdist ships the prebuilt notebook and JupyterLab extensions; skip
# the jupyter-builder hook, which rebuilds them with jlpm and needs npm
# network access
MAKE_ENV=	HATCH_BUILD_NO_HOOKS=true

NO_ARCH=	yes

.include <bsd.port.mk>
