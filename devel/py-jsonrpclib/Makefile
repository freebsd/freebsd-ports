# New ports collection makefile for:	py-jsonrpclib
# Date created:				09. 21. 2011
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	jsonrpclib
PORTVERSION=	0.1.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bra@fsn.hu
COMMENT=	Implements the JSON-RPC 2.0 proposed specification in pure Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cjson.so:${PORTSDIR}/devel/py-cjson

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
