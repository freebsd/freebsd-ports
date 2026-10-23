PORTNAME=	trimesh
DISTVERSION=	5.1.1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library for loading and using triangular meshes
WWW=		https://trimesh.org/ \
		https://github.com/mikedh/trimesh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mapbox-earcut>=1.0.2:math/py-mapbox-earcut@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycollada>0:graphics/py-pycollada@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtree>0:devel/py-rtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shapely>0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>0:devel/py-xxhash@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	mikedh

NO_ARCH=	yes

# skipped tests need unavailable optional modules (pyinstrument, manifold3d, a working svg.path, matplotlib),
# test_obb_mesh_large is a timing test that fails on slow machines
TEST_ARGS=	--disable-plugin-autoload \
		-p xdist -n 8 \
		--ignore=tests/test_svg.py \
		--ignore=tests/test_sweep.py \
		--deselect=tests/test_bounds.py::BoundsTest::test_obb_mesh_large \
		--deselect=tests/test_meta.py::MetaTest::test_svg \
		--deselect=tests/test_paths.py::test_plot \
		--deselect=tests/test_paths.py::test_svg_arc_snap \
		--deselect=tests/test_ray.py::test_contains_cavity \
		--deselect=tests/test_splines.py::SplineTests::test_bezier_example
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 5.1.1: 742 passed, 3 skipped, 292 warnings in 252.21s

.include <bsd.port.mk>
