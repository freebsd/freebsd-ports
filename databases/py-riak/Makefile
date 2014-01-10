# Created by: TJ Ninneman <tj@harperdog.com>
# $FreeBSD$

PORTNAME=	riak
PORTVERSION=	1.4.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python API for Riak, a Dynamo-inspired key/value store

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=2.4.0:${PORTSDIR}/devel/py-protobuf

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
