# Created by: Ivan Voras <ivoras@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdcached
PORTVERSION=	1.0.9
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	The PHP client library for Bullet Cache (mdcached)

LICENSE=	BSD

LIB_DEPENDS=	libmdcached.so:${PORTSDIR}/databases/mdcached

USE_PHP=	yes
USE_PHPEXT=	yes
CONFIGURE_ARGS=	--enable-mdcached
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}/client_php/${PORTNAME}

.include <bsd.port.mk>
