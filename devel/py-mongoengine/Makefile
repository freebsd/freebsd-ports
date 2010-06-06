# New ports collection makefile for:	py-mongoengine
# Date created:		2010-06-04
# Whom:			Mirko Zinn <mail@derzinn.de>
#
# $FreeBSD$
#

PORTNAME=	mongoengine
PORTVERSION=	0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@derzinn.de
COMMENT=	A Python Object-Document-Mapper for working with MongoDB

RUN_DEPENDS=	pymongo>=1.6:${PORTSDIR}/databases/pymongo

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
