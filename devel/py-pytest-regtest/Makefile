PORTNAME=	pytest-regtest
PORTVERSION=	2.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_regtest-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pytest plugin for regression tests
WWW=		https://gitlab.com/uweschmitt/pytest-regtest \
		https://pypi.org/project/pytest-regtest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest
NO_ARCH=	yes

.include <bsd.port.mk>
