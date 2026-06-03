PORTNAME=	finvizfinance
DISTVERSION=	1.2.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finviz Finance information downloader
WWW=		https://finvizfinance.readthedocs.io/en/latest/ \
		https://github.com/lit26/finvizfinance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

NO_ARCH=	yes

post-extract:
	@${TOUCH} ${WRKSRC}/README_pypi.md

# tests as of 1.1.0: 20 passed in 32.56s
# tests as of 1.2.0: 12 passed, 58 warnings, 7 errors in 7.21, see https://github.com/lit26/finvizfinance/issues/140

.include <bsd.port.mk>
