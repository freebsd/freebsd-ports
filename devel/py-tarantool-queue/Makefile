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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tarantool>=0:${PORTSDIR}/databases/py-tarantool \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0:${PORTSDIR}/devel/py-msgpack

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALLS_EGGINFO=yes
PYDISTUTILS_AUTOPLIST=yes

do-configure:
	${REINPLACE_CMD} -i -e "1d" ${WRKSRC}/setup.py

.include <bsd.port.mk>
