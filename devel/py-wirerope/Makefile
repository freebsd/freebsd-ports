PORTNAME=	wirerope
PORTVERSION=	1.0.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Turn functions and methods into fully controllable objects
WWW=		https://github.com/youknowone/wirerope

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 3 tests fail, see https://github.com/youknowone/wirerope/issues/22

USE_GITHUB=	yes
GH_ACCOUNT=	youknowone

NO_ARCH=	yes

# tests as of 1.0.0: 9 passed in 1.37s

.include <bsd.port.mk>
