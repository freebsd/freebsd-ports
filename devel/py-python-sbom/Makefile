PORTNAME=	python-sbom
DISTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SBOMs for Python distributions: PEP 770 CycloneDX SBOMs in wheels
WWW=		https://github.com/tox-dev/python-sbom

LICENSE=	MIT APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_APACHE20=	${WRKSRC}/src/python_sbom/_validate/schemas/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=25.1:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.5:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.32.4:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=1.1:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packageurl-python>=0.11.1:textproc/py-packageurl-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipremove>=0.10:devel/py-zipremove@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}installer>=1.1:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packageurl-python>=0.11.1:textproc/py-packageurl-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=26.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipremove>=0.10:devel/py-zipremove@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}covdefaults>=2.3:devel/py-covdefaults@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.28:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=1.1:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema-rs>=0.60.3:devel/py-jsonschema-rs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdm-backend>=2.4:devel/py-pdm-backend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=7.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.15.1:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.5:misc/py-spdx-tools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} PATH=${STAGEDIR}${PREFIX}/bin:${PATH}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_cov \
		-p pytest_mock \
		--import-mode=importlib \
		--no-cov

# tests as of 0.3.1: 689 passed, 9 skipped in 313.55s

.include <bsd.port.mk>
