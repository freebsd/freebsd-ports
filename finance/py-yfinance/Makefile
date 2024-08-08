PORTNAME=	yfinance
PORTVERSION=	0.2.41
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yahoo! Finance market data downloader
WWW=		https://github.com/ranaroussi/yfinance

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.11.1:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozendict>=2.3.4:devel/py-frozendict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=1.1:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.9.1:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multitasking>=0.0.7:devel/py-multitasking@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16.5,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.3.0,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}peewee>=3.15.0:databases/py-peewee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.0.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2022.5,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
