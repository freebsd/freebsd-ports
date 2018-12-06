# Created by: <mbowie@buzmo.com>
# $FreeBSD$

PORTNAME=	tclink
PORTVERSION=	4.0.2
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	https://vault.trustcommerce.com/downloads/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-php

MAINTAINER=	mbowie@buzmo.com
COMMENT=	PHP extension for TrustCommerce credit card processing

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

USES=		php:ext ssl

IGNORE_WITH_PHP=	71 72 73

post-patch:
	# avoid name conflicts with libressl
	${REINPLACE_CMD} -e 's|\(X509_STORE_load_mem\)|uniq_\1|g' \
			 -e 's|\(X509_LOOKUP_mem\)|uniq_\1|g' ${WRKSRC}/mem.c

.include <bsd.port.mk>
