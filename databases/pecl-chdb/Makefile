# New ports collection makefile for:	pecl-chdb
# Date created:			26 January 2012
# Whom:				Evan Sarmiento <esarmiento@wayfair.com>
#
# $FreeBSD$
#

PORTNAME=	chdb
PORTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/lcastelli/chdb/tarball/${DISTVERSION}/
PKGNAMEPREFIX=	pecl-
DISTNAME=	lcastelli-${PORTNAME}-v${DISTVERSION}-0-g${DISTVERSION}
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CHDB extension

BUILD_DEPENDS=	${LOCALBASE}/lib/libcmph.so:${PORTSDIR}/devel/cmph
RUN_DEPENDS=	${LOCALBASE}/lib/libcmph.so:${PORTSDIR}/devel/cmph

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	chdb
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CFLAGS+=	-L${LOCALBASE}/lib

GITVERSION=	5c9a37d
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/lcastelli-${PORTNAME}-${GITVERSION}

CONFIGURE_ARGS=	--with-libcmph-dir=${LOCALBASE}/lib

.include <bsd.port.mk>
