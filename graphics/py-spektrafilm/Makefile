PORTNAME=	spektrafilm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spectral simulation of analog photography processes
WWW=		https://github.com/andreavolpato/spektrafilm

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openimageio>=3.1.8:graphics/py-openimageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colour-science>=0.4.6:graphics/py-colour-science@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}exiv2>=0.18.1:graphics/py-exiv2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lensfunpy>=1.18.0:graphics/py-lensfunpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.7:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.10:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napari>=0.6.6:misc/py-napari@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.64:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.4,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opt-einsum>=3.4.0:math/py-opt-einsum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=12.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyFFTW>=0.15.0:math/py-pyFFTW@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyconify>=0.2.1:devel/py-pyconify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>=6.9:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=2.4:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rawpy>=0.26.1:graphics/py-rawpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.26:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.17:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opencolorio>=2.5:graphics/py-opencolorio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	andreavolpato

NO_ARCH=	yes

# the deselected snapshot tests differ in the darkest ramp values with the versions of dependencies in the tree
TEST_ARGS=	--disable-plugin-autoload \
		--deselect 'tests/test_regression_baselines.py::TestRegressionBaselines::test_pipeline_snapshot[print_rgb_fuji_crystal_gray_ramp16]' \
		--deselect 'tests/test_regression_baselines.py::TestRegressionBaselines::test_pipeline_snapshot[print_rgb_portra_endura_gray_ramp16]'
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		QT_API=pyside6 QT_QPA_PLATFORM=offscreen

# tests as of 0.3.3: 808 passed, 2 deselected, 14 warnings in 23.36s

.include <bsd.port.mk>
