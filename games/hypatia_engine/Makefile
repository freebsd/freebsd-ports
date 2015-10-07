# $FreeBSD$

PORTNAME=	hypatia_engine
PORTVERSION=	0.2.29
CATEGORIES=	games python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lillian.lynn.lemmer@gmail.com
COMMENT=	Game engine for 2D top-down, tile-based action RPGs

LICENSE=	MIT

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}pyganim>0:${PORTSDIR}/graphics/py-pyganim \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}enum34>0:${PORTSDIR}/devel/py-enum34

USES=		python:2
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
