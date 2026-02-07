PORTNAME=	omegaconf
DISTVERSION=	2.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible configuration library
WWW=		https://github.com/omry/omegaconf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}antlr4-python3-runtime>0:devel/py-antlr4-python3-runtime@${PY_FLAVOR}

USES=		java:build python

USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

NO_ARCH=	yes

# tests as of 2.3.0: 10 failed, 7761 passed, 354 skipped, 8 xfailed in 57.22s, failures are because if the missing build_helpers/test_files

.include <bsd.port.mk>
