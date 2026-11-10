PORTNAME=	pyvo
PORTVERSION=	1.10.0
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for accessing Virtual Observatory data and services
WWW=		https://pyvo.readthedocs.io/en/latest/ \
		https://github.com/astropy/pyvo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=5.0:astro/py-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-astropy>=0.6:astro/py-pytest-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-astropy-header>0:astro/py-pytest-astropy-header@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-doctestplus>=0.13:devel/py-pytest-doctestplus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_astropy_header.display \
		-p pytest_doctestplus.plugin \
		-p pytest_remotedata.plugin \
		-p pytest_skip_slow \
		-p pytest_timeout \
		-p requests_mock.contrib._pytest_plugin \
		--ignore=pyvo/samp/tests/test_web_profile.py # hangs in teardown

# tests as of 1.10.0: 525 passed, 106 skipped, 1 xfailed in 33.84s (remote-data tests are skipped; run with astropy 7.1.1 import-shimmed for numpy 2.4 np.in1d removal)

.include <bsd.port.mk>
