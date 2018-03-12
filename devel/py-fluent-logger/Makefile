# Created by: Edward Chuang <edwardchuang@gmail.com>
# $FreeBSD$

PORTNAME=	fluent-logger
PORTVERSION=	0.9.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	edwardchuang@gmail.com
COMMENT=	Structured logger for Fluentd (Python)

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>0:devel/py-msgpack-python@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
