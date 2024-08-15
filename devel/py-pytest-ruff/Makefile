PORTNAME=	pytest-ruff
DISTVERSION=	0.4.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTest plugin to check ruff requirements
WWW=		https://github.com/businho/pytest-ruff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-dynamic-versioning>0:devel/py-poetry-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=5:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.0.242:devel/py-ruff@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.10.0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest # tests are broken due to https://github.com/businho/pytest-ruff/issues/30

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
