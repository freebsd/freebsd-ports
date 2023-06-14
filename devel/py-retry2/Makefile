PORTNAME=	retry2
DISTVERSION=	0.9.5
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy to use retry decorator in python
WWW=		https://github.com/eSAMTrade/retry

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=3.4.2:devel/py-decorator@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	eSAMTrade
GH_PROJECT=	retry

NO_ARCH=	yes

do-test: install
	@cd ${WRKSRC} && ${PYTHON_CMD} tests/test_retry.py && ${ECHO} "Tests succeeded"

.include <bsd.port.mk>
