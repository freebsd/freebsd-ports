# Ports collection makefile for:  pear-Horde_Cache
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Cache
PORTVERSION=	2.1.0
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Caching API

OPTIONS_DEFINE=	APC MEMCACHE
APC_DESC=	Require APC PHP extension
MEMCACHE_DESC=	Enable Memcache support
		
USE_HORDE_RUN=	Horde_Compress_Fast Horde_Exception Horde_Util
USE_PHP=	hash

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPC}
USE_PHP+=	apc
.endif

.if ${PORT_OPTIONS:MMEMCACHE}
USE_HORDE_RUN+=	Horde_Memcache
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
