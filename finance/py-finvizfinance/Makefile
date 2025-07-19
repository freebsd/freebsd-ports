PORTNAME=	finvizfinance
DISTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finviz Finance information downloader
WWW=		https://finvizfinance.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.12.3:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

NO_ARCH=	yes

post-extract:
	@${TOUCH} ${WRKSRC}/README_pypi.md

# tests as of 1.1.0: 20 passed in 32.56s

.include <bsd.port.mk>
