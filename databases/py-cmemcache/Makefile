# Created by: Qing Feng <qingfeng@douban.com>
# $FreeBSD$

PORTNAME=	cmemcache
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://gijsbert.org/downloads/cmemcache/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python API for memcached, a distributed memory cache daemon

LIB_DEPENDS=	libmemcache.so:${PORTSDIR}/databases/libmemcache

USES=			tar:bzip2
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DEPRECATED=	Deprecated upstream
EXPIRATION_DATE=2014-06-12

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000000
BROKEN=	Does not build with CLANG or GCC greater than 4.2
.endif

.include <bsd.port.post.mk>
