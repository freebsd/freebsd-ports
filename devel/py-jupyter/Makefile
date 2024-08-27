PORTNAME=	jupyter
DISTVERSION=	1.0.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # the jupyter project installs a file conflicting with jupyter_core, see https://github.com/jupyter/jupyter_core/issues/405
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Jupyter metapackage that installs all the Jupyter components in one go
WWW=		https://jupyter.org/

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_console>0:devel/py-jupyter_console@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>0:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook>0:www/py-notebook@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qtconsole>0:devel/py-qtconsole@${PY_FLAVOR}

USES=		metaport python

.include <bsd.port.mk>
