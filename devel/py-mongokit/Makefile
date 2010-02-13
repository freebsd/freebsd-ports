# New ports collection makefile for:	py-mongokit
# Date created:		2010-02-06
# Whom:			Mirko Zinn <mail@derzinn.de>
#
# $FreeBSD$
#

PORTNAME=	mongokit
PORTVERSION=	0.5.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@derzinn.de
COMMENT=	Python ORM-like layer on top of pymongo

RUN_DEPENDS=	pymongo>=1.3:${PORTSDIR}/databases/pymongo \
		${PYTHON_PKGNAMEPREFIX}anyjson>=0.2.3:${PORTSDIR}/devel/py-anyjson

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
