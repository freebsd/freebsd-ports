PORTNAME=	pick
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pick an option in the terminal with a simple GUI
WWW=		https://github.com/aisk/pick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	aisk

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

# tests as of 2.4.0: 8 passed in 2.51s

.include <bsd.port.mk>
