# New ports collection makefile for:	openjpeg
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	openjpeg
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.openjpeg.org/
DISTNAME=	openjpeg_v1_1

MAINTAINER=	trasz@pin.if.uz.zgora.pl
COMMENT=	An open-source JPEG 2000 codec

USE_GMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/OpenJPEG/
PLIST_FILES=	lib/libopenjpeg.a lib/libopenjpeg-1.0.0.so lib/libopenjpeg.so.1
CFLAGS+=	"-fPIC"

.include <bsd.port.mk>
