PORTNAME=	finvizfinance
DISTVERSION=	1.5.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Finviz Finance information downloader
WWW=		https://finvizfinance.readthedocs.io/en/latest/ \
		https://github.com/lit26/finvizfinance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.9:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.6:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.5:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlsxwriter>=3.0:textproc/py-xlsxwriter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

# tests disabled: upstream test suite relies on live finviz.com HTML which
# has changed, causing 7 errors and 1 failure, see
# https://github.com/lit26/finvizfinance/issues/140

.include <bsd.port.mk>
