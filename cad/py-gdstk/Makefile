PORTNAME=	gdstk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.55
CATEGORIES=	cad
#MASTER_SITES=	PYPI # some test files are missing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for creation and manipulation of GDSII and OASIS files
WWW=		https://heitzmann.github.io/gdstk/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>0:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYNUMPY}
LIB_DEPENDS=	libqhull_r.so:math/qhull
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++17-lang python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	heitzmann

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
