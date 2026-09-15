PORTNAME=	cibuildwheel # doesn't fully support FreeBSD
DISTVERSION=	4.2.1
CATEGORIES=	devel science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Build Python wheels on CI with minimal configuration
WWW=		https://cibuildwheel.pypa.io/en/stable/ \
		https://github.com/pypa/cibuildwheel

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bashlex>=0.13:devel/py-bashlex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bracex>0:textproc/py-bracex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}build>=1.0.0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dependency-groups>=1.2:devel/py-dependency-groups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>0:devel/py-humanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=9:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validate-pyproject>0:devel/py-validate-pyproject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdoctest>0:devel/py-xdoctest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_rerunfailures -p xdoctest

post-patch:
	@${RM} ${WRKSRC}/*/*.orig ${WRKSRC}/*/*/*.orig ${WRKSRC}/*/*/*/*.orig 2>/dev/null || ${TRUE}

# tests as of 4.2.1: 851 passed, 71 skipped, 3 xfailed in 5.74s (unit_test only)

.include <bsd.port.mk>
