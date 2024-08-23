PORTNAME=	alpha-vantage
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0-4
DISTVERSIONSUFFIX=	-gd18224b
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Module to get stock data from the Alpha Vantage Api
WWW=		https://github.com/RomelTorres/alpha_vantage

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/RomelTorres/alpha_vantage/issues/340

USE_GITHUB=	yes
GH_ACCOUNT=	RomelTorres
GH_PROJECT=	alpha_vantage

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/test_alpha_vantage

.include <bsd.port.mk>
