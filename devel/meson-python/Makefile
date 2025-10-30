PORTNAME=	meson-python
DISTVERSION=	0.18.0
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	meson_python-${DISTVERSION}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Meson Python build backend (PEP-517)
WWW=		https://github.com/mesonbuild/meson-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	meson:devel/meson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.9.0:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PY_TOMLI}
RUN_DEPENDS=	meson:devel/meson@${PY_FLAVOR} \
		patchelf>0:sysutils/patchelf \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0.9.0:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_TYPING_EXTENSIONS} \
		git:devel/git

USES=		python
USE_PYTHON=	autoplist concurrent cython3_test pep517 pytest

# tarball has UTF-8 filenames
EXTRACT_CMD=	env LANG=C.UTF-8 LC_ALL=C.UTF-8 ${TAR}
NO_ARCH=	yes

.include <bsd.port.mk>
