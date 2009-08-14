# New ports collection makefile for:	py-memcached
# Date created:		2004-04-16
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	memcached
PORTVERSION=	1.44
CATEGORIES=	databases python
MASTER_SITES=	ftp://ftp.tummy.com/pub/python-memcached/ \
		ftp://ftp.tummy.com/pub/python-memcached/old-releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Python API for memcached, a distributed memory cache daemon

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	python-memcached

.include <bsd.port.mk>
