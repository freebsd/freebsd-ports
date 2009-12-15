# New ports collection makefile for:	pecl-newt
# Date created:		2009-06-02
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	newt
PORTVERSION=	1.2.4
CATEGORIES=	devel www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	PHP language extension for RedHat Newt library

LIB_DEPENDS=	newt.51:${PORTSDIR}/devel/newt

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	newt

post-patch:
	@${REINPLACE_CMD} -e '/SEARCH_PATH/ s,=",="${LOCALBASE} ${PREFIX} ,' \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
