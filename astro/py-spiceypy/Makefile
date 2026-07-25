PORTNAME=	spiceypy
DISTVERSIONPREFIX=	v
DISTVERSION=	8.2.0
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for the NAIF C SPICE Toolkit
WWW=		https://github.com/AndrewAnnex/SpiceyPy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR}
LIB_DEPENDS=	libcspice.so:astro/cspice
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.23.5:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=2.2.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	autoplist cython pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	AndrewAnnex
GH_PROJECT=	SpiceyPy

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	spiceypy

PYTEST_IGNORED_TESTS=	test_wrapper test_context_manager test_gettestkernels test_cyice \
		test_no_loaded_files_exception test_no_loaded_files_exception_cyice

post-patch: # pin the version and remove scikit-build-core dynamic-metadata that requires project.dynamic
	@${REINPLACE_CMD} -e 's|^name = "spiceypy"|name = "spiceypy"\nversion = "${DISTVERSION}"|' \
		-e '/^dynamic = \["version"\]/d' \
		-e '/^# Scrape __version__/,/^# pytest things/d' \
		${WRKSRC}/pyproject.toml

# Tests as of 8.2.0: tests requiring SPICE kernels downloaded at runtime are ignored.
# The remaining tests run against the installed package so the compiled cyice extension is found.
# See https://github.com/AndrewAnnex/SpiceyPy for details
# tests as of 8.2.0: 42 passed, 1074 deselected

.include <bsd.port.mk>
