PORTNAME=	financetoolkit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.3
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Transparent and efficient financial analysis
WWW=		https://www.jeroenbouma.com/projects/financetoolkit \
		https://github.com/JerBouma/FinanceToolkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=2.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.6:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yfinance>0:finance/py-yfinance@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx2>=0.28:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=6.29:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=5.0.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-recording>=0.13.2:devel/py-pytest-recording@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}time-machine>0:devel/py-time-machine@${PY_FLAVOR}
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fastmcp>0:misc/py-fastmcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	JerBouma
GH_PROJECT=	FinanceToolkit

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 2.0.0: 3 failed, 277 passed, 25 errors in 190.04s (0:03:10)
# tests as of 2.1.3: 522 passed, 58 skipped, 2 warnings in 27.56s

.include <bsd.port.mk>
