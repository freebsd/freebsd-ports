PORTNAME=	pytest-jupyter
PORTVERSION=	0.11.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyter-server/pytest-jupyter/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_jupyter-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	pytest plugin for testing Jupyter libraries and extensions
WWW=		https://pytest-jupyter.readthedocs.io/en/main/ \
		https://github.com/jupyter-server/pytest-jupyter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.10.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-core>=5.7:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7.0,1:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CLIENT SERVER
OPTIONS_DEFAULT=CLIENT SERVER
CLIENT_DESC=	Client-side support
SERVER_DESC=	Server-side support
SERVER_IMPLIES=	CLIENT

CLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>=6.14:devel/py-ipykernel@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}jupyter-client>=7.4.0:devel/py-jupyter-client@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}nbformat>=5.3:devel/py-nbformat@${PY_FLAVOR}
SERVER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>=6.14:devel/py-ipykernel@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}jupyter-client>=7.4.0:devel/py-jupyter-client@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}jupyter-server>=1.21:devel/py-jupyter-server@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}nbformat>=5.3:devel/py-nbformat@${PY_FLAVOR}

.include <bsd.port.mk>
