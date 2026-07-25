PORTNAME=	duckdb
DISTVERSION=	1.5.5
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system
WWW=		https://duckdb.org/

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake-core \
		ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.6.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	pep517 autoplist

MAKE_ENV=	OVERRIDE_GIT_DESCRIBE=v${DISTVERSION}-g00000000 \
		CMAKE_EXECUTABLE=${LOCALBASE}/bin/cmake \
		NINJA_EXECUTABLE=${LOCALBASE}/bin/ninja

# tests as of 1.5.5: not shipped in the PyPI source tarball

.include <bsd.port.mk>
