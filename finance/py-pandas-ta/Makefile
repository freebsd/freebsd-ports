PORTNAME=	pandas-ta
DISTVERSION=	0.3.14
PORTREVISION=	2
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Market Technical Analysis indicators in Python and Pandas
WWW=		https://twopirllc.github.io/pandas-ta/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.2.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2021.1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16.0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ta-lib>0:finance/py-ta-lib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/twopirllc/pandas-ta/issues/631

USE_GITHUB=	yes
GH_ACCOUNT=	twopirllc

NO_ARCH=	yes

.include <bsd.port.mk>
