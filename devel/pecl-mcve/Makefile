# New ports collection makefile for:	pecl-mcve
# Date created:			14,May 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mcve
PORTVERSION=	7.0.1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	wenheping@gmail.com
COMMENT=	A PECL Extension for Interface the MCVE/Monetra API

LIB_DEPENDS=	monetra.7:${PORTSDIR}/devel/libmonetra

USE_PHP=	yes
USE_PHPEXT=	yes
CONFIGURE_ARGS+=--with-mcve="${LOCALBASE}"

post-patch:
	${REINPLACE_CMD} -e '/SEARCH_PATH/ s,=",="${LOCALBASE} ${PREFIX} ,' \
		${WRKSRC}/config.m4

.include <bsd.port.mk>
