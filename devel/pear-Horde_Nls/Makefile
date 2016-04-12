# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Nls
PORTVERSION=	2.2.0
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.horde.org/get/
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Native Language Support

USES=		horde
USE_HORDE_RUN=	Horde_Translation \
		Horde_Util

OPTIONS_DEFINE=	GEOIP
GEOIP_DESC=	Depend on geoip PHP extension

GEOIP_USE=	PHP=yes
GEOIP_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/geoip.so:net/pecl-geoip

.include <bsd.port.mk>
