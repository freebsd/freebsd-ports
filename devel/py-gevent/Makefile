# New ports collection makefile for: py-gevent
# Date created:		5 Feb 2010
# Whom:			Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$
#

PORTNAME=	gevent
PORTVERSION=	0.13.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Python co-routine networking library based on greenlet/libevent

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}greenlet>=0.3.1:${PORTSDIR}/devel/py-greenlet

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

.include <bsd.port.mk>
