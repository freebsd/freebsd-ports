PORTNAME=	cytoolz
DISTVERSION=	1.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython implementation of Toolz: High performance functional utilities
WWW=		https://github.com/pytoolz/cytoolz

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-git-versioning>=2.0:devel/py-setuptools-git-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toolz>=0.8.0:devel/py-toolz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/cytoolz/tests
TEST_ARGS=	--disable-plugin-autoload --import-mode=importlib

pre-test:
	@${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cytoolz/*.so ${WRKSRC}/cytoolz/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/*.so

# tests as of 1.2.0: 195 passed, 1 skipped in 0.48s

.include <bsd.port.mk>
