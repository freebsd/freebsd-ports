# New ports collection makefile for:	py-memcached
# Date created:		2004-04-16
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	memcached
PORTVERSION=	1.2
CATEGORIES=	databases
MASTER_SITES=	http://www.danga.com/memcached/dist/
PKGNAMEPREFIX=	py-
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python API for memcached, a distributed memory cache daemon

RUN_DEPENDS=	memcached:${PORTSDIR}/databases/memcached

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
