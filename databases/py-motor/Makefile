# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	motor
PORTVERSION=	0.7
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Non-blocking MongoDB driver for Tornado or asyncio

LICENSE=	APACHE20

RUN_DEPENDS=    ${PYTHON_PKGNAMEPREFIX}pymongo>=2.9.4:databases/pymongo

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
