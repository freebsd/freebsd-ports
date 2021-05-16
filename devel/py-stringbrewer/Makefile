# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	stringbrewer
PORTVERSION=	0.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate random strings matching a pattern

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rstr>=0:devel/py-rstr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sre-yield>=0:devel/py-sre-yield@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
