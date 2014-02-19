# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	jsonrpclib
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bra@fsn.hu
COMMENT=	Implements the JSON-RPC 2.0 proposed specification in pure Python

LICENSE=	APACHE20

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=	CJSON
CJSON_DESC=	Use cjson instead of json or simplejson

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCJSON}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cjson>0:${PORTSDIR}/devel/py-cjson
.endif

.include <bsd.port.mk>
