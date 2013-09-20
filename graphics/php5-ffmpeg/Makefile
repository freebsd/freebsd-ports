# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	0.6.0
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}-php/${PORTNAME}-php/${PORTVERSION}
PKGNAMEPREFIX=	php5-
DISTNAME=	${PORTNAME}-php-${PORTVERSION}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The ffmpeg shared extension for php

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg

CFLAGS+=	-I${LOCALBASE}/include
USE_BZIP2=	yes
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-ffmpeg=${LOCALBASE}/include

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|==|=|g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
