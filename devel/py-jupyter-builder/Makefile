PORTNAME=	jupyter-builder
PORTVERSION=	1.2.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_builder-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JupyterLab build tools
WWW=		https://github.com/jupyterlab/jupyter-builder

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE ISCL MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE=	${WRKSRC}/THIRD_PARTY_LICENSES/yarn.js.LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>=0.3.2:devel/py-hatch-nodejs-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.21.1:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-core>=0:devel/py-jupyter-core@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
