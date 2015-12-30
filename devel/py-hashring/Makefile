# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	hashring
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hash_ring-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of consistent hashing in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=0:${PORTSDIR}/databases/py-python-memcached

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
