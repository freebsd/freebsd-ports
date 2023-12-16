PORTNAME=	fastf1
PORTVERSION=	3.1.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Python module to accessing and analyzing Formula 1 data
WWW=		https://github.com/theOehrly/Fast-F1

LICENSE=	MIT

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.3.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-cache>=0:www/py-requests-cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}signalr-client-aio>=0:devel/py-signalr-client-aio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thefuzz>=0:devel/py-thefuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timple>=0:math/py-timple@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
