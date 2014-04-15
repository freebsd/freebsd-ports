# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	simplecouchdb
PORTVERSION=	0.9.26
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Library to Allow Python Applications to Use CouchDB

LICENSE=	MIT

DEPRECATED=	Obsolete, abandoned
EXPIRATION_DATE=2014-07-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>0:${PORTSDIR}/www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}py-restclient>0:${PORTSDIR}/www/py-py-restclient
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	py_${PORTNAME}

post-extract:
	${MV} ${WRKSRC}/tests ${WRKSRC}/simplecouchdb/

.include <bsd.port.mk>
