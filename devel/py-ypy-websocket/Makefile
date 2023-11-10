PORTNAME=	ypy-websocket
PORTVERSION=	0.12.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ypy_websocket-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WebSocket connector for Ypy
WWW=		https://davidbrochart.github.io/ypy-websocket/ \
		https://github.com/y-crdt/ypy-websocket

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>=0.18.0<1:databases/py-aiosqlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anyio>=3.6.2<5:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}y-py>=0.6.0<0.7.0:devel/py-y-py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DJANGO
DJANGO_DESC=	Django support

DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}channels>=0:www/py-channels@${PY_FLAVOR}

.include <bsd.port.mk>
