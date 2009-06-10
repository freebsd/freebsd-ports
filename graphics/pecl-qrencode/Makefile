# New ports collection makefile for:	pecl-qrencode
# Date created:				Apr 16 2007
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	qrencode
PORTVERSION=	0.3
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

CONFIGURE_ARGS=	--with-qrencode=${PREFIX}
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${EXTRA_LIBS}"

.include <bsd.port.mk>
