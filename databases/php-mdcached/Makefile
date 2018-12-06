# Created by: Ivan Voras <ivoras@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdcached
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ivoras@FreeBSD.org
COMMENT=	The PHP client library for Bullet Cache (mdcached)

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libmdcached.so:databases/mdcached

USES=		php:ext
IGNORE_WITH_PHP=	71 72 73
CONFIGURE_ARGS=	--enable-mdcached
WRKSRC_SUBDIR=		${PORTNAME}/client_php/${PORTNAME}

.include <bsd.port.mk>
