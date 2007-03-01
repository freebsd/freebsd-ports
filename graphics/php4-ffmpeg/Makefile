# New ports collection makefile for:	php4-ffmpeg
# Date created:		2006-10-19
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}-${PKGNAMEPREFIX:S/4-//:S/5-//}
PKGNAMEPREFIX?=	php4-
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX:S/4-//:S/5-//}-${PORTVERSION}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The ffmpeg shared extension for php

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		gd.4:${PORTSDIR}/graphics/gd

USE_BZIP2=	yes
USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP?=5
DEFAULT_PHP_VER?=4
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include

.include <bsd.port.mk>
