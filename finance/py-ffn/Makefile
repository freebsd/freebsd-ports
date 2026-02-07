PORTNAME=	ffn
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Financial functions for Python
WWW=		http://pmorissette.github.io/ffn/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=5.0.7:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.15:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas-datareader>=0.2:math/py-pandas-datareader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.19:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.15:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.15:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.7.5:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yfinance>=0.2:finance/py-yfinance@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}seaborn>=0:math/py-seaborn@${PY_FLAVOR} # optional dependency

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pmorissette

NO_ARCH=	yes

# tests as of 1.1.2: 54 passed, 6 warnings in 495.57s (0:08:15)

.include <bsd.port.mk>
