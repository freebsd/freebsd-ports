PORTNAME=	jupyter
DISTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI # the jupyter project installs a file conflicting with jupyter_core, see https://github.com/jupyter/jupyter_core/issues/405
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Jupyter metapackage that installs all the Jupyter components in one go
WWW=		https://jupyter.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_console>0:devel/py-jupyter_console@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>0:devel/py-jupyterlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>0:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook>0:www/py-notebook@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist # metaport, but it has a tarball that contains nothing essential

.include <bsd.port.mk>
