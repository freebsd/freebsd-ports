# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP extension for expect library

LICENSE=	PHP301

LIB_DEPENDS=	libexpect.so:lang/expect

USES=		php:ext tar:tgz tcl:86
IGNORE_WITH_PHP=	70

CFLAGS+=	-I${TCL_INCLUDEDIR}
CONFIGURE_ARGS+=--with-expect=${LOCALBASE}

.include <bsd.port.mk>
