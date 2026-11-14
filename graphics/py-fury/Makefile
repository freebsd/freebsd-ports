PORTNAME=	fury
DISTVERSION=	2.1.0
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Free Unified Rendering in Python
WWW=		https://fury.gl/latest/index.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glfw>=2.7.0:graphics/py-glfw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.4:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.4.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polyxios>=0.2.0:graphics/py-polyxios@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygfx>=0.16.0:graphics/py-pygfx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.13.0:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.9.0:math/py-matplotlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -p no:cacheprovider \
		--ignore=fury/actor --ignore=fury/ui \
		--ignore=fury/tests/test_convert.py --ignore=fury/tests/test_window.py \
		--deselect fury/tests/test_io.py::test_load_image_as_wgpu_texture_view_uses_show_manager_device # tests that need a GPU with full WebGPU features are excluded

NO_ARCH=	yes

# tests as of 2.1.0: 263 passed, 9 skipped, 1 deselected, 1 warning in 5.23s

.include <bsd.port.mk>
