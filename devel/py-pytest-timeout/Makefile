PORTNAME=	pytest-timeout
PORTVERSION=	2.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Pytest plugin to abort hanging tests
WWW=		https://github.com/pytest-dev/pytest-timeout

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=7.0.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

TEST_ENV+=	PYTHONPATH=${TEST_WRKSRC}

NO_ARCH=	yes

.include <bsd.port.mk>
