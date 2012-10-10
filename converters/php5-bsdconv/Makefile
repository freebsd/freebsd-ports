# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bsdconv
PORTVERSION=	9.0
CATEGORIES=	converters
PKGNAMEPREFIX=	php5-
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	PHP wrapper for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	bsdconv:${PORTSDIR}/converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	php-${PORTNAME}
GH_COMMIT=	314309f

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
PHP_MODNAME=	${PORTNAME}
CONFIGURE_ARGS=	--with-bsdconv=${LOCALBASE}

.include <bsd.port.mk>
