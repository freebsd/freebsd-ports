# New ports collection makefile for:	pecl-expect
# Date created:			2006/08/17
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	expect
PORTVERSION=	0.2.5
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A PHP extension for expect library

LIB_DEPENDS=	expect543:${PORTSDIR}/lang/expect

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=--with-expect=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e \
	  's/\(LIBRARY_WITH_PATH(\)expect/\1expect543/' \
	  ${WRKSRC}/config.m4

.include <bsd.port.mk>
