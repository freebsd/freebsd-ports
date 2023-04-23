PORTNAME=	fredapi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python API for Federal Reserve Economic Data (FRED) from St. Louis Fed
WWW=		https://github.com/mortada/fredapi

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.15:math/py-pandas@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/mortada/fredapi/issues/60

USE_GITHUB=	yes
GH_ACCOUNT=	mortada

NO_ARCH=	yes

.include <bsd.port.mk>
