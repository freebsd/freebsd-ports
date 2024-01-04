PORTNAME=	soxr
DISTVERSION=	0.3.7
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High quality, one-dimensional sample-rate conversion library
WWW=		https://github.com/dofuuz/python-soxr

LICENSE=	LGPL21 BSD3CLAUSE
LICENSE_COMB=	multi

BROKEN_i386=	fails to compile: ...requires target feature 'sse', but would be inlined into function 'h8' that is compiled without support for 'sse'

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYNUMPY} \
		${PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	# strip binary
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/soxr/cysoxr${PYTHON_EXT_SUFFIX}.so
	# correct version as a workaround for https://github.com/dofuuz/python-soxr/issues/21
	@${REINPLACE_CMD} -i '' -e 's|^version |__version__ |' ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/soxr/_version.py

.include <bsd.port.mk>
