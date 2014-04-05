# $FreeBSD$

PORTNAME=	Horde_HashTable
PORTVERSION=	1.1.2
CATEGORIES=	databases www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Hash Table Interface

OPTIONS_DEFINE=	MEMCACHE
USE_HORDE_RUN=	Horde_Exception

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMEMCACHE}
USE_HORDE_RUN+=	Horde_Memcache
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
