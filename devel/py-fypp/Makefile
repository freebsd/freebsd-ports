PORTNAME=	fypp
DISTVERSION=	3.3
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # missing files needed for tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python powered preprocessor
WWW=		https://github.com/aradi/fypp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	aradi

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test
TEST_ARGS=	--disable-plugin-autoload

# tests as of 3.3: 462 passed in 0.34s

.include <bsd.port.mk>
