# Created by: vanilla
# $FreeBSD$

PORTNAME=	qrencode
PORTVERSION=	0.4
CATEGORIES=	graphics pear
MASTER_SITES=	LOCAL/vanilla
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	PECL extension for generate qrcode

LIB_DEPENDS=	libqrencode.so:${PORTSDIR}/graphics/libqrencode

USE_PHP=	yes
USE_PHPEXT=	yes
USES=	tar:bzip2

CONFIGURE_ARGS=	--with-qrencode=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
