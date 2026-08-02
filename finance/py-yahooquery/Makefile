PORTNAME=	yahooquery
DISTVERSION=	2.4.1
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for an unofficial Yahoo Finance API
WWW=		https://yahooquery.dpguthrie.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.12.2:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}curl-cffi>=0.10.0:ftp/py-curl-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.9.3:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>=1.0.1:www/py-requests-futures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.65.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
