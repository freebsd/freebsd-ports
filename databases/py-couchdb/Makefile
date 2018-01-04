# Created by: Andrei Antoukh <niwi@niwi.be>
# $FreeBSD$

PORTNAME=	CouchDB
PORTVERSION=	1.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	niwi@niwi.be
COMMENT=	Simple Library to Allow Python Applications to Use CouchDB

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=    ${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent pythonprefix

.include <bsd.port.mk>
