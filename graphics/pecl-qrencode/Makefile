# Created by: vanilla
# $FreeBSD$

PORTNAME=	qrencode
PORTVERSION=	0.4
CATEGORIES=	graphics pear
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vanilla
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A PECL extension for generate qrcode

LIB_DEPENDS=	qrencode.3:${PORTSDIR}/graphics/libqrencode

USE_PHP=	yes
USE_PHPEXT=	yes
USE_BZIP2=	yes

CONFIGURE_ARGS=	--with-qrencode=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}
CFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.mk>
