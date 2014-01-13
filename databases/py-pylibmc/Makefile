# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	pylibmc
PORTVERSION=	1.2.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Python libmemcached wrapper

LICENSE=	BSD

LIB_DEPENDS=	libmemcached.so:${PORTSDIR}/databases/libmemcached

MAKE_ENV+=	LIBMEMCACHED="${LOCALBASE}"
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
