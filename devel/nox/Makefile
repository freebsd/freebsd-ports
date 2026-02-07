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

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.9.4<4.0:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=23.1:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=2.6.1<7.0.0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dependency-groups>=1.1:devel/py-dependency-groups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.14.1:devel/py-virtualenv@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	wntrblm
GH_TAGNAME=	2025.02.09

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

BINARY_ALIAS=	python3=${PYTHON_CMD} # for tests

NO_ARCH=	yes

# tests as of 2024.10.09: 542 passed, 31 skipped, 1 xpassed in 52.39s
# tests as of 2025.02.09: 22 failed, 581 passed, 30 skipped, 1 xpassed in 58.55s, see https://github.com/wntrblm/nox/issues/926

.include <bsd.port.mk>
