# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tarantool-queue
PORTVERSION=	0.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Python bindings for Tarantool queue

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tarantool>=0:databases/py-tarantool \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>=0:devel/py-msgpack-python

USES=		python
USE_PYTHON=	distutils autoplist

do-configure:
	${REINPLACE_CMD} -i -e "1d" ${WRKSRC}/setup.py

.include <bsd.port.mk>
