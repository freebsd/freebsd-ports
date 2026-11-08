PORTNAME=	duckdb
DISTVERSION=	2.0.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system
WWW=		https://duckdb.org/

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake-core \
		ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}nanobind>=3.0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	pep517 autoplist

MAKE_ENV=	OVERRIDE_GIT_DESCRIBE=v${DISTVERSION} \
		CMAKE_EXECUTABLE=${LOCALBASE}/bin/cmake \
		NINJA_EXECUTABLE=${LOCALBASE}/bin/ninja

# tests as of 2.0.0: not shipped in the PyPI source tarball

.include <bsd.port.mk>
