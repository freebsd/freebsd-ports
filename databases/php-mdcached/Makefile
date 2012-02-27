# New ports collection makefile for:	php-mdcached
# Date created:			8 February 2012
# Whom:				Ivan Voras <ivoras@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdcached
PORTVERSION=	1.0.2
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	The PHP client library for Bullet Cache (mdcached)

LIB_DEPENDS=	mdcached.1:${PORTSDIR}/databases/mdcached

USE_PHP=	yes
USE_PHPEXT=	yes
CONFIGURE_ARGS=	--enable-mdcached
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}/client_php/${PORTNAME}

.include <bsd.port.mk>
