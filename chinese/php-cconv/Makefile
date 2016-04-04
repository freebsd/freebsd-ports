# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cconv
PORTVERSION=	0.6.4
DISTVERSIONPREFIX=	php-
CATEGORIES=	chinese converters
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	php-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP wrapper for chinese/cconv

LICENSE=	GPLv2

LIB_DEPENDS=	libcconv.so:chinese/cconv

CONFIGURE_ARGS=	--with-cconv-dir=${LOCALBASE}
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

post-patch:
	@${REINPLACE_CMD} -e 's| function_entry| zend_function_entry|' ${WRKSRC}/php_cconv.c

.include <bsd.port.mk>
