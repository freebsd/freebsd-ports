# Created by: ijliao
# $FreeBSD$

PORTNAME=	simpleparse
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SimpleParse-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python EBNF parser generator (with mx.TextTools derivative)

OPTIONS_DEFINE=	MXBASE
# This one is only needed because of mx.DateTime
MXBASE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mx-base>0:${PORTSDIR}/lang/py-mx-base

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
