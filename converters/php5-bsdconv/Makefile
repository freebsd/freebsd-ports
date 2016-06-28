# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bsdconv
PORTVERSION=	11.3.0
CATEGORIES=	converters
PKGNAMEPREFIX=	php5-

MAINTAINER=	buganini@gmail.com
COMMENT=	PHP wrapper for bsdconv

LICENSE=	ISCL

LIB_DEPENDS=	libbsdconv.so:converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	php-${PORTNAME}

USES=		php:ext
IGNORE_WITH_PHP=	70
CONFIGURE_ARGS=	--with-bsdconv=${LOCALBASE}

.include <bsd.port.mk>
