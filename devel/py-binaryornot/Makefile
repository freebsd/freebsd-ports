PORTNAME=	binaryornot
DISTVERSION=	0.6.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Lightweight pure Python package to check if a file is binary or text
WWW=		https://github.com/binaryornot/binaryornot

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv>0:devel/py-uv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
# Both tests depends on files that aren't included in the sdist tarball
PYTEST_BROKEN_TESTS=	test_negative_binary test_unreadable_file_raises

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
