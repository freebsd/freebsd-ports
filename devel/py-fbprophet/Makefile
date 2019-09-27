# $FreeBSD$

PORTNAME=	fbprophet
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Forecasting time series data based on an additive model

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 python
USE_PYTHON=	autoplist distutils

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pystan>2.14:math/py-pystan@${PY_FLAVOR}

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pystan>2.14:math/py-pystan@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>1.10.0:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}matplotlib>2.0.0:math/py-matplotlib@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pandas>0.23.4:math/py-pandas@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}holidays>0.9.5:devel/py-holidays@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}lunardate>0.1.5:devel/py-lunardate@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}convertdate>2.1.2:devel/py-convertdate@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
