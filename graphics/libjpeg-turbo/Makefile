# New ports collection makefile for:   libjpeg-turbo
# Date created:		2010-04-09
# Date modified:	2010-04-12
# Whom:			Denis Podolskiy bytestore@yandex.ru (based on D. R. Commander)
#
# $FreeBSD$
#

PORTNAME=	libjpeg-turbo
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	bytestore@yandex.ru
COMMENT=	SIMD-accelerated JPEG codec which provides both the libjpeg,TurboJPEG

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

CONFLICTS=	jpeg-[0-9]*
ONLY_FOR_ARCHS=	amd64 i386
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	SO_MAJOR_VERSION=${SOVERSION} CFLAGS+=-fPIC
CONFIGURE_ARGS=	--with-jpeg8
USE_LDCONFIG=	yes

MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1
PLIST_SUB=	SOVERSION=${SOVERSION}

# chase graphics/jpeg
SOVERSION=	11

.include <bsd.port.mk>
