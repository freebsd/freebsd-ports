# New ports collection makefile for:	pecl-expect
# Date created:			2006/08/17
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	expect
PORTVERSION=	0.2.3
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A PHP extension for expect library

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c
LIB_DEPENDS=	expect543:${PORTSDIR}/lang/expect

USE_PHP=	yes
USE_PHPEXT=	yes

post-patch:
	@${REINPLACE_CMD} -e '16 s,expect,expect543,' ${WRKSRC}/config.m4

.include <bsd.port.mk>
