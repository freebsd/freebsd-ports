PORTNAME=	pycoingecko
DISTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper around the CoinGecko API
WWW=		https://github.com/man-c/pycoingecko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	man-c

NO_ARCH=	yes

.include <bsd.port.mk>
