# New ports collection makefile for:	py-pylibmc
# Date created:		2009-11-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	pylibmc
PORTVERSION=	1.2.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Python libmemcached wrapper

LICENSE=	BSD

LIB_DEPENDS=	memcached:${PORTSDIR}/databases/libmemcached

MAKE_ENV+=	LIBMEMCACHED="${LOCALBASE}"
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
