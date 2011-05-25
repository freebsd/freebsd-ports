# Ports collection makefile for:  php5-bsdconv
# Date created:			  23 May 2009
# Whom:				  buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	5.0
CATEGORIES=	converters
MASTER_SITES=	https://github.com/buganini/php-${PORTNAME}/tarball/${PORTVERSION}/
PKGNAMEPREFIX=	php5-
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	PHP wrapper for bsdconv

LIB_DEPENDS=	bsdconv.5:${PORTSDIR}/converters/bsdconv

LICENSE=	BSD

GITVERSION=	7037d27
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-php-${PORTNAME}-${GITVERSION}

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
PHP_MODNAME=	${PORTNAME}
CONFIGURE_ARGS=	--with-bsdconv=${LOCALBASE}

.include <bsd.port.mk>
