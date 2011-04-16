# Ports collection makefile for:  php5-bsdconv
# Date created:			  23 May 2009
# Whom:				  buganini@gmail.com
#
# $FreeBSD$
#

CATEGORIES+=	converters
PKGNAMEPREFIX=	php5-

MAINTAINER=	buganini@gmail.com
COMMENT=	PHP wrapper for bsdconv

LIB_DEPENDS=	bsdconv.4:${PORTSDIR}/converters/bsdconv

MASTERDIR=	${.CURDIR}/../bsdconv
WRKSRC=		${WRKDIR}/${DISTNAME}/wrapper/php
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${NONEXISTENT}

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	bsdconv
CONFIGURE_ARGS+=--with-bsdconv=${LOCALBASE}

.include "${MASTERDIR}/Makefile"
