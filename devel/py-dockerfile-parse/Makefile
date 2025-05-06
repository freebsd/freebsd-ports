PORTNAME=	dockerfile-parse
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tuukka.pasanen@ilmi.fi
COMMENT=	Python library for Dockerfile manipulation
WWW=		https://github.com/containerbuildsystem/dockerfile-parse

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
PYTEST_BROKEN_TESTS=	test_all_versions_match

NO_ARCH=	YES

.include <bsd.port.mk>
