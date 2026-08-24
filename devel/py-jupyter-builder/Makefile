PORTNAME=	jupyter-builder
PORTVERSION=	1.2.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_builder-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JupyterLab build tools
WWW=		https://github.com/jupyterlab/jupyter-builder

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>=0.3.2:devel/py-hatch-nodejs-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.21.1:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-core>=0:devel/py-jupyter-core@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
