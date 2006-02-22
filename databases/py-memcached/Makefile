# New ports collection makefile for:	py-memcached
# Date created:		2004-04-16
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	memcached
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	databases python
MASTER_SITES=	ftp://ftp.tummy.com/pub/python-memcached/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${DISTVERSION:S/$/_tummy${PORTREVISION}/}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Python API for memcached, a distributed memory cache daemon

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
