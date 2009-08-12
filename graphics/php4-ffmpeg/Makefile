# New ports collection makefile for:	php4-ffmpeg
# Date created:		2006-10-19
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}-php
PKGNAMEPREFIX=	php4-
DISTNAME=	${PORTNAME}-php-${PORTVERSION}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The ffmpeg shared extension for php

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg

BROKEN=		does not compile with ffmpeg 0.5 and later
DEPRECATED=	development continues only for php5
EXPIRATION_DATE=	2009-10-12

CFLAGS+=	-I${LOCALBASE}/include
DEFAULT_PHP_VER=4
IGNORE_WITH_PHP=5
USE_BZIP2=	yes
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-ffmpeg=${LOCALBASE}/include

.include <bsd.port.mk>
