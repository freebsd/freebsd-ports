PORTNAME=	itertree
DISTVERSION=	1.1.3
CATEGORIES=	devel
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python tree structure for data storage and iterations
WWW=		https://github.com/BR1py/itertree

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 1 test fails, see https://github.com/BR1py/itertree/issues/18

USE_GITHUB=	yes
GH_ACCOUNT=	BR1py
GH_TAGNAME=	1,1,3

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/./-/g}

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
