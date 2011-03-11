# New ports collection makefile for:   libjpeg-turbo
# Date created:		2010-04-09
# Date modified:	2010-04-12
# Whom:			Denis Podolskiy bytestore@yandex.ru (based on D. R. Commander)
#
# $FreeBSD$
#

PORTNAME=	libjpeg-turbo
PORTVERSION=	1.1.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	bytestore@yandex.ru
COMMENT=	SIMD-accelerated JPEG codec which provides both the libjpeg,TurboJPEG

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

CONFLICTS=	jpeg-[0-9]*
ONLY_FOR_ARCHS=	amd64 i386
USE_AUTOTOOLS=	autoconf autoheader aclocal automake libtool
ACLOCAL_ARGS=	-I.
USE_LDCONFIG=	yes

MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1

.include <bsd.port.mk>
