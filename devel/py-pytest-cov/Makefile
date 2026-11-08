PORTNAME=	pytest-cov
PORTVERSION=	7.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Pytest plugin for measuring coverage
WWW=		https://github.com/pytest-dev/pytest-cov

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7.10.6:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=1.2:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7,1:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}process-tests>0:devel/py-process-tests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ARGS+=	-p pytester

.include <bsd.port.mk>
