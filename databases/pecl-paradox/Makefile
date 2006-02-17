# Ports collection makefile for:  pecl-paradox
# Date created:			  2006-02-11
# Whom:				  Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	paradox
DISTVERSION=	1.4.1
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	An extension to read and write Paradox files

LIB_DEPENDS=	px.6:${PORTSDIR}/databases/pxlib

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4
PHP_MODNAME=	paradox

CONFIGURE_ARGS+=	--with-paradox=${LOCALBASE}
CONFIGURE_ENV=		CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -E 's/(lib -lm) -ldl/\1 -liconv -lintl/g' \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
