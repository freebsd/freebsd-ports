# Created by: Mikhail T.  <m.tsatsenko@gmail.com>

PORTNAME=	backtrader
PORTVERSION=	1.9.74.123
PORTREVISION=	1
CATEGORIES=	finance python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Python Backtesting library for trading strategies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.7+
USE_GITHUB=	yes # Does not distribute sdist via PyPI
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	PLOTTING TALIB

PLOTTING_DESC=	Support graphical plotting output
TALIB_DESC=	ta-lib support via finance/py-ta-lib

PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
TALIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ta-lib>0:finance/py-ta-lib@${PY_FLAVOR}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v tests

.include <bsd.port.mk>
