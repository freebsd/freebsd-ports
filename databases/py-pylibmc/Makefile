# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	pylibmc
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python wrapper around the libmemcached interface

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libmemcached.so:${PORTSDIR}/databases/libmemcached

USES=		python:2
USE_PYTHON=	distutils autoplist

MAKE_ENV+=	LIBMEMCACHED="${LOCALBASE}"

.include <bsd.port.mk>
