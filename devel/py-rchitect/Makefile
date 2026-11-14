PORTNAME=	rchitect
DISTVERSION=	0.6.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interoperate R with Python
WWW=		https://github.com/randy3k/rchitect

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.10.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.10.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	R>0:math/R \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion -Wno-error=incompatible-function-pointer-types
.endif

TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# test_reticulate.py requires the R reticulate package; test_host* re-exec python with R's gcc14 LD_LIBRARY_PATH which breaks _ctypes
TEST_ARGS=	--disable-plugin-autoload -p pytest_mock \
		--ignore=test_reticulate.py \
		--deselect=tests/test_utils.py::test_host \
		--deselect=tests/test_utils.py::test_host_r_binary_arg

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rchitect/_cffi_lib.abi3.so

# tests as of 0.6.0: 42 passed, 3 skipped, 2 deselected in 4.73s

.include <bsd.port.post.mk>
