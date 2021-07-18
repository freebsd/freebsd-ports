PORTNAME=	python-engineio
PORTVERSION=	3.14.2
PORTREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of the Engine.IO realtime client and server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNCIO_CLIENT CLIENT
OPTIONS_DEFAULT=ASYNCIO_CLIENT CLIENT
CLIENT_DESC=	Standard client support
ASYNCIO_CLIENT_DESC=	Asynchronous client support

ASYNCIO_CLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.4:www/py-aiohttp@${PY_FLAVOR}
CLIENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websocket-client>=0.54.0:www/py-websocket-client@${PY_FLAVOR}

.include <bsd.port.mk>
