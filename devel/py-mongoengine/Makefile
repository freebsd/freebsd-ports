# Created by: Mirko Zinn <mail@derzinn.de>
# $FreeBSD$

PORTNAME=	mongoengine
PORTVERSION=	0.10.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Object-Document-Mapper for working with MongoDB

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}rednose>0:devel/py-rednose
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=2.7:databases/pymongo

USES=		python
USE_PYTHON=	autoplist distutils

# bson is provided by pymongo
post-patch:
	@${RM} -r ${WRKSRC}/bson

.include <bsd.port.mk>
