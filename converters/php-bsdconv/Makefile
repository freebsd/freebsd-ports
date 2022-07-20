PORTNAME=	bsdconv
PORTVERSION=	11.6.0
CATEGORIES=	converters
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	buganini@gmail.com
COMMENT=	PHP wrapper for bsdconv

LICENSE=	ISCL

LIB_DEPENDS=	libbsdconv.so:converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	php-${PORTNAME}

USES=		php:ext
CONFIGURE_ARGS=	--with-bsdconv=${LOCALBASE}

.include <bsd.port.mk>
