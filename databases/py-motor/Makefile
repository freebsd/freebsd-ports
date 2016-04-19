# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	motor
PORTVERSION=	0.6.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Non-blocking MongoDB driver for Tornado or asyncio

LICENSE=	APACHE20

RUN_DEPENDS=    ${PYTHON_SITELIBDIR}/pymongo-2.8-py${PYTHON_VER}.egg-info/PKG-INFO:databases/pymongo28

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
