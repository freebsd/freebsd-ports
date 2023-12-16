PORTNAME=	nbdime
PORTVERSION=	4.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyter/nbdime/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Diff and merge of Jupyter notebooks
WWW=		https://github.com/jupyter/nbdime

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.5:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.5.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=0:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server-mathjax>=0.2.2:devel/py-jupyter-server-mathjax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	jupyter

post-extract:
	@${RM} ${WRKSRC}/nbdime/labextension/schemas/nbdime-jupyterlab/package.json.orig

.include <bsd.port.mk>
