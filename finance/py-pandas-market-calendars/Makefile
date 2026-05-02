PORTNAME=	pandas-market-calendars
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3.2
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Market and exchange trading calendars for pandas
WWW=		https://github.com/rsheftel/pandas_market_calendars

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}exchange-calendars>=3.3:finance/py-exchange-calendars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>0:devel/py-tzdata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	rsheftel
GH_PROJECT=	${PORTNAME:S/-/_/g}

NO_ARCH=	yes

# tests as of 5.3.2: 1471 passed, 1 failed in 47.10s

.include <bsd.port.mk>
