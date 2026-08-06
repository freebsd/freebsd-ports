PORTNAME=	pyvista
DISTVERSION=	0.48.4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pythonic interface to VTK
WWW=		https://github.com/pyvista/pyvista

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cyclopts>=4.0.0:devel/py-cyclopts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.0.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pooch>0:devel/py-pooch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scooby>=0.5.1:devel/py-scooby@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.10:devel/py-typing-extensions@${PY_FLAVOR} \
		vtk${VTK_VER:R}>0:math/vtk${VTK_VER:R}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} MPLBACKEND=agg
TEST_WRKSRC=	${WRKSRC}
TEST_ARGS=	-o filterwarnings=default -p no:cov -p no:black -p no:mypy -p no:benchmark \
		tests/test_init.py tests/test_meta.py tests/test_warn_external.py
PYTEST_IGNORED_TESTS=	test_plotting_attribute_cached test_pyvista_oo_flag test_plotting_getattr_called_once

# The full test suite requires a display/GUI environment and the pytest-pyvista
# helper which is not yet packaged for FreeBSD. Only a small set of safe tests is
# run. The skipped tests fail because the math/vtk9 package does not include the
# vtkRenderingMatplotlib module.
# tests as of 0.48.4: 7 passed in 4.40s (3 ignored due to missing VTK module)

NO_ARCH=	yes

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
