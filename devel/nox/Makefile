PORTNAME=	nox
PORTVERSION=	${GH_TAGNAME:S/.0/./g} # .whl file built w/out zeros in the version, possibly based on some clause in the standard
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible test automation
WWW=		https://nox.thea.codes/en/stable \
		https://github.com/wntrblm/nox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.9.4:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=24.1:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=2.6.1<7.0.0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dependency-groups>=1.1:devel/py-dependency-groups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=4:devel/py-humanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22:devel/py-packaging@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.15:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	wntrblm
GH_TAGNAME=	2026.04.10

TEST_ENV=	${MAKE_ENV} \
		PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

PYTEST_IGNORED_TESTS=	test_noxfile_script_mode_url_req \
			test_uv_install

BINARY_ALIAS=	python3=${PYTHON_CMD} # for tests

NO_ARCH=	yes

# tests as of 2026.04.10: 681 passed, 36 skipped, 7 deselected, 1 xpassed in 23.08s

.include <bsd.port.mk>
