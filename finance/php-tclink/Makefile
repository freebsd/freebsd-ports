# Created by: <mbowie@buzmo.com>
# $FreeBSD$

PORTNAME=	tclink
PORTVERSION=	4.0.2
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	https://vault.trustcommerce.com/downloads/
PKGNAMEPREFIX=	php-
DISTNAME=	${PORTNAME}-${PORTVERSION}-php

MAINTAINER=	mbowie@buzmo.com
COMMENT=	PHP extension for TrustCommerce credit card processing

USES=		php:ext ssl

IGNORE_WITH_PHP=	70 71 72

post-patch:
	# avoid name conflicts with libressl
	${REINPLACE_CMD} -e 's|\(X509_STORE_load_mem\)|uniq_\1|g' \
			 -e 's|\(X509_LOOKUP_mem\)|uniq_\1|g' ${WRKSRC}/mem.c

.include <bsd.port.mk>
