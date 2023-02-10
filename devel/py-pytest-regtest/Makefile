PORTNAME=	pytest-regtest
PORTVERSION=	1.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Pytest plugin for regression tests
WWW=		https://gitlab.com/uweschmitt/pytest-regtest \
		https://pypi.org/project/pytest-regtest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

.include <bsd.port.mk>
