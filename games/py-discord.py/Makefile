PORTNAME=	discord.py
PORTVERSION=	2.0.1
CATEGORIES=	games python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	API wrapper for Discord written in Python
WWW=		https://github.com/Rapptz/discord.py

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
