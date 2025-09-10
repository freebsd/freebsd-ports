PORTNAME=	phmdoctest
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python syntax highlighted Markdown doctest
WWW=		https://tmarktaylor.github.io/phmdoctest/ \
		https://github.com/tmarktaylor/phmdoctest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.1.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}CommonMark>=0.9.1:textproc/py-CommonMark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monotable>=2.1.1:devel/py-monotable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 1.4.0: 4 failed, 227 passed in 49.71s (4 failues due to missing .github/*** files)

.include <bsd.port.mk>
