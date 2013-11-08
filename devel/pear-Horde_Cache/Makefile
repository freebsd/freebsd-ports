# $FreeBSD$

PORTNAME=	Horde_Cache
PORTVERSION=	2.3.0
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Caching API

OPTIONS_DEFINE=	APC
APC_DESC=	Require APC PHP extension
		
USE_HORDE_RUN=	Horde_Compress_Fast \
		Horde_Exception \
		Horde_HashTable \
		Horde_Util
USE_PHP=	hash

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPC}
USE_PHP+=	apc
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
