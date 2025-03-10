PORTNAME=	fbprophet
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmm@tutanota.com
COMMENT=	Forecasting time series data based on an additive model
WWW=		https://github.com/facebook/prophet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired math/py-pystan
EXPIRATION_DATE=2025-03-31

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
