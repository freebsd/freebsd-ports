# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tarantool-queue
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for Tarantool queue

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tarantool>=0:databases/py-tarantool@${PY_FLAVOR}

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''
USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@${REINPLACE_CMD} -e 's|msgpack-python|msgpack|; s|tarantool<0.4|tarantool|' ${WRKSRC}/setup.py ${WRKSRC}/tarantool_queue.egg-info/requires.txt

.include <bsd.port.mk>
