# Created by: Mikhail T.  <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	backtrader
PORTVERSION=	1.9.74.123
CATEGORIES=	finance python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Python Backtesting library for trading strategies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes # Does not distribute sdist via PyPI
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	PLOTTING

PLOTTING_DESC=	Support graphical plotting output

PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v tests

.include <bsd.port.mk>
