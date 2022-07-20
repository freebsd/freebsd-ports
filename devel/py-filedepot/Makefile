PORTNAME=	filedepot
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for storing files and attachments in web applications

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyascii>=0:textproc/py-anyascii@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
