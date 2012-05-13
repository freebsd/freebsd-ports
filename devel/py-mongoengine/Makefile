# New ports collection makefile for:	py-mongoengine
# Date created:		2010-06-04
# Whom:			Mirko Zinn <mail@derzinn.de>
#
# $FreeBSD$
#

PORTNAME=	mongoengine
PORTVERSION=	0.6.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@derzinn.de
COMMENT=	A Python Object-Document-Mapper for working with MongoDB

LICENSE=	MIT

RUN_DEPENDS=	pymongo>=2.1:${PORTSDIR}/databases/pymongo

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
