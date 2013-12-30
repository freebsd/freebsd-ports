# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	hashring
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hash_ring-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of consistent hashing in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}memcached>=0:${PORTSDIR}/databases/py-memcached

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
