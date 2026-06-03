PORTNAME=	zstandard
DISTVERSION=	0.25.0
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Zstandard bindings for Python, a full-featured version
WWW=		https://github.com/indygreg/python-zstandard

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.17:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
#LIB_DEPENDS=	libzstd.so:archivers/zstd
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	pep517 autoplist
#PYDISTUTILS_BUILDARGS=	--system-zstd # breaks in runtime due to version mismatch, keep disabled until this is fixed: https://github.com/indygreg/python-zstandard/issues/132

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zstandard && ${STRIP_CMD} backend_c*.so _cffi*.so

do-test: # runs the internal testsuite, tests are unreliable or faulty: https://github.com/indygreg/python-zstandard/issues/133
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILDARGS} test

# tests as of 0.25.0: Ran 292 tests in 0.199s

.include <bsd.port.mk>
