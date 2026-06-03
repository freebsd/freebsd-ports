PORTNAME=	soxr
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High quality, one-dimensional sample-rate conversion library
WWW=		https://github.com/dofuuz/python-soxr

LICENSE=	LGPL21 BSD3CLAUSE
LICENSE_COMB=	multi

BROKEN_i386=	fails to compile: ...requires target feature 'sse', but would be inlined into function 'h8' that is compiled without support for 'sse'

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.9.0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SoundFile>0:audio/py-SoundFile@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
