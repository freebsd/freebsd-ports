# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	0.2.9
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PHP extension for expect library

LIB_DEPENDS=	expect543:${PORTSDIR}/lang/expect

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=4

CONFIGURE_ARGS+=--with-expect=${LOCALBASE}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
	  's/\(LIBRARY_WITH_PATH(\)expect/\1expect543/' \
	  ${WRKSRC}/config.m4

.include <bsd.port.mk>
