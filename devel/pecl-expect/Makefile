# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	devel pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP extension for expect library

LICENSE=	PHP301

LIB_DEPENDS=	libexpect.so:lang/expect

USES=		php:pecl tcl

CFLAGS+=	-I${TCL_INCLUDEDIR}
CONFIGURE_ARGS=	--with-expect=${LOCALBASE}

.include <bsd.port.mk>
