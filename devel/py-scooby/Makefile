PORTNAME=	scooby
DISTVERSION=	0.12.1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python environment detective
WWW=		https://github.com/banesullivan/scooby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-console-scripts>0:devel/py-pytest-console-scripts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} PATH=${STAGEDIR}${PREFIX}/bin:$$PATH
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_console_scripts \
		-p pytest_cov

# tests/test_scooby.py::test_import_os_error requires pyvips to fail to import;
# tests/test_scooby.py::test_get_version and test_tracking require the no-version
# package, which is not currently in FreeBSD ports.
PYTEST_BROKEN_TESTS=	test_get_version test_tracking test_import_os_error

# tests as of 0.12.1: 30 passed, 1 skipped, 3 deselected in 27.64s

.include <bsd.port.mk>
