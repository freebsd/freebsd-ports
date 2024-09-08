PORTNAME=	fluent-logger
DISTVERSION=	0.11.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fluent_logger-${DISTVERSION}

MAINTAINER=	edwardchuang@gmail.com
COMMENT=	Structured logger for Fluentd (Python)
WWW=		https://github.com/fluent/fluent-logger-python

LICENSE=	APACHE20

BUILD_DEPENDS=	py311-hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
