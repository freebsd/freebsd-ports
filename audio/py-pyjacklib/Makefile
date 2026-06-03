PORTNAME=	pyjacklib
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for libjack using ctypes
WWW=		https://github.com/jackaudio/pyjacklib

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libjack.so:audio/jack

USES=		localbase python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
