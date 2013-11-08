# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Nls
PORTVERSION=	2.0.3
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.horde.org/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Native Language Support

USE_HORDE_RUN=	Horde_Translation \
		Horde_Util

OPTIONS_DEFINE=	GEOIP
GEOIP_DESC=	Depend on geoip PHP extension

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEOIP}
USE_PHP=	yes
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGEOIP}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/geoip.so:${PORTSDIR}/net/pecl-geoip
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
