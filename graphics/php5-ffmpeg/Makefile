# New ports collection makefile for:	php4-ffmpeg
# Date created:		2006-10-19
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}-php/${PORTNAME}-php/${PORTVERSION}
PKGNAMEPREFIX=	php5-
DISTNAME=	${PORTNAME}-php-${PORTVERSION}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The ffmpeg shared extension for php

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg

CFLAGS+=	-I${LOCALBASE}/include
DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4
USE_BZIP2=	yes
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-ffmpeg=${LOCALBASE}/include

.include <bsd.port.mk>
