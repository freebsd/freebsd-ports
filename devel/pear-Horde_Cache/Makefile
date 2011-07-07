# Ports collection makefile for:  pear-Horde_Cache
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Cache
PORTVERSION=	1.0.4
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Horde Caching API

OPTIONS=	APC "Require APC PHP extension" Off \
		MEMCACHE "Enable Memcache support" Off \
		
USE_HORDE_RUN=	Horde_Exception Horde_Util
USE_PHP=	hash

.include <bsd.port.pre.mk>

.if defined(WITH_APC)
USE_PHP+=	apc
.endif

.if defined(WITH_MEMCACHE)
USE_HORDE_RUN+=	Horde_Memcache
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
