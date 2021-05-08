# Created by: jessekempf@gmail.com

PORTNAME=	daemon
PORTVERSION=	2.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-daemon-${PORTVERSION}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Well-behaved daemon framework for Python

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lockfile>=0.10:devel/py-lockfile@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
