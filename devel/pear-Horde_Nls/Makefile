# Ports collection makefile for:  pear-Horde_Nls
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Nls
PORTVERSION=	1.1.0
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.horde.org/get/
PKGNAMEPREFIX=	pear-

OPTIONS=	GEOIP "Depend on geoip PHP extension" Off

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Native Language Support

USE_HORDE_RUN=	Horde_Translation Horde_Util

.include <bsd.port.pre.mk>

.if defined(WITH_GEOIP)
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/geoip.so:${PORTSDIR}/net/pecl-geoip
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
