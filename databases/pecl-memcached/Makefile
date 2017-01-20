# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	2.2.0
PORTREVISION=	5
CATEGORIES=	databases
PKGNAMEPREFIX=	pecl-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for interfacing with memcached via libmemcached library

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmemcached.so:databases/libmemcached

OPTIONS_DEFINE=	IGBINARY SASL
IGBINARY_DESC=	Binary serializer support

PORTSCOUT=	limit:^[0-9\.]*$$

CONFIGURE_ARGS=	--with-libmemcached-dir=${LOCALBASE}
USE_PHP=	json:build session:build
USES=		php:ext pkgconfig

PHP7_TAGNAME=	e65be32

GH_TUPLE=	php-${PORTNAME}-dev:php-${PORTNAME}:${PORTVERSION} \
		php-${PORTNAME}-dev:php-${PORTNAME}:${PHP7_TAGNAME}:php7
USE_GITHUB=	yes

IGBINARY_CONFIGURE_ENABLE=	memcached-igbinary
IGBINARY_USE=		PHP=igbinary:build
SASL_CONFIGURE_ENABLE=	memcached-sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

.include <bsd.port.pre.mk>

.if ${PHP_VER} >= 70
WRKSRC_SUBDIR=	../php-${PORTNAME}-${PHP7_TAGNAME}
.endif

.include <bsd.port.post.mk>
