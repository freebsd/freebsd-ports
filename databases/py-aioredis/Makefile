# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aioredis
PORTVERSION=	1.1.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Python asyncio based Redis client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhiredis.so:databases/hiredis

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
