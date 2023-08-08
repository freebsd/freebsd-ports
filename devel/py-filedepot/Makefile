PORTNAME=	filedepot
PORTVERSION=	0.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for storing files and attachments in web applications
WWW=		https://github.com/amol-/depot

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyascii>=0:textproc/py-anyascii@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
