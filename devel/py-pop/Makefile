# Created by: Kirill Ponomarev <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=		pop
PORTVERSION=	14
CATEGORIES=		devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Plugin Oriented Programming interface for Python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>=0:devel/py-aiofiles@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}aiologger>=0:devel/py-aiologger@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}dict-toolbox>=0:sysutils/py-dict-toolbox@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pop-config>0:devel/py-pop-config@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist distutils

USE_GITLAB=	yes
GL_ACCOUNT=	saltstack/pop
GL_COMMIT=	d7b457b5fdee7f6feb0fe8f19a34633b4ec9992a

NO_ARCH=	yes

.include <bsd.port.mk>
