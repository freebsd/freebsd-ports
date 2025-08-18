PORTNAME=	rjieba
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.13
CATEGORIES=	chinese python
#MASTER_SITES=	PYPI # doesn't get into distinfo
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chinese words segmentation utilities
WWW=		https://github.com/messense/rjieba-py

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	messense
GH_PROJECT=	rjieba-py

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=${WRKSRC}/target

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of 0.1.13: 6 passed in 2.03s

.include <bsd.port.mk>
