# Created by: Mirko Zinn <mail@derzinn.de>
# $FreeBSD$

PORTNAME=	minimongo
PORTVERSION=	0.2.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://files.derzinn.de/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@derzinn.de
COMMENT=	Minimal database Model management for MongoDB

RUN_DEPENDS=	pymongo>=1.9:${PORTSDIR}/databases/pymongo

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
