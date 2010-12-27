# New ports collection makefile for:	py-riak
# Date created:				2010-12-10
# Whom:					TJ Ninneman <tj@harperdog.com>
#
# $FreeBSD$
#

PORTNAME=	riak
PORTVERSION=	1.1.1
CATEGORIES=	databases python
MASTER_SITES=	http://github.com/downloads/tee-jay/riak-python-client/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-client-${PORTVERSION}

MAINTAINER=	tj@harperdog.com
COMMENT=	Python API for Riak, a Dynamo-inspired key/value store

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>0:${PORTSDIR}/devel/py-protobuf

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

FETCH_ARGS=	-pRr

.include <bsd.port.mk>
