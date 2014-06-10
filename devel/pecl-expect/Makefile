# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	0.2.9
PORTREVISION=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP extension for expect library

LIB_DEPENDS=	libexpect.so:${PORTSDIR}/lang/expect

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=--with-expect=${LOCALBASE}

.include <bsd.port.mk>
