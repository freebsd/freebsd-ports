# New ports collection makefile for:	py-umemcache
# Date created:		2012-08-18
# Whom:			Kubilay Kocak <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	umemcache
PORTVERSION=	1.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Memcache client written in highly optimized C++ with Python bindings

LICENSE=	BSD

USE_DOS2UNIX=	yes
USE_ZIP=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/umemcache.so

.include <bsd.port.mk>
