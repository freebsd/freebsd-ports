PORTNAME=	ccxt
DISTVERSION=	2.4.61
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cryptocurrency trading API with support for 100+ exchanges
WWW=		https://github.com/ccxt/ccxt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2018.1.18:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.6.1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist pytest # 2 tests fail, see https://github.com/ccxt/ccxt/issues/16221

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-extract: # workaround for https://github.com/ccxt/ccxt/issues/16220
	@${TOUCH} ${WRKSRC}/README.md

.include <bsd.port.mk>
