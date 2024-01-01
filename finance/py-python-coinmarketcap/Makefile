PORTNAME=	python-coinmarketcap
DISTVERSION=	0.5
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CoinMarketCap Python API Wrapper
WWW=		https://github.com/rsz44/python-coinmarketcap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.2.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
