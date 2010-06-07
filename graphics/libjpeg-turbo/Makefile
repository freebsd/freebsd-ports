# New ports collection makefile for:   libjpeg-turbo
# Date created:		2010-04-09
# Date modified:	2010-04-12
# Whom:			Denis Podolskiy bytestore@yandex.ru (based on D. R. Commander)
#
# $FreeBSD$
#

PORTNAME=	libjpeg-turbo
PORTVERSION=	0.0.93
CATEGORIES=	graphics
MASTER_SITES=	http://openmoko.spb.ru/repository/ \
		http://mesh.dl.sourceforge.net/project/libjpeg-turbo/${PORTVERSION}/ \
		${MASTER_SITE_XCONTRIB}

MAINTAINER=	bytestore@yandex.ru
COMMENT=	SIMD-accelerated JPEG codec which provides both the libjpeg,TurboJPEG

CONFLICTS=	jpeg-[0-9]*
ONLY_FOR_ARCH=	amd64 i386
USE_AUTOTOOLS=	autoconf:262 automake:110 libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

BUILD_DEPENDS+=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm:install

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS=	--host x86_64-unknown-freebsd
.else
CONFIGURE_ARGS=	--host ${ARCH}-unknown-freebsd
.endif

pre-configure:
	@${ECHO_CMD} configure jpeg-turbo library
	@cd ${WRKDIR}/libjpeg-turbo-${PORTVERSION} && ${AUTORECONF} -fiv && ${LIBTOOLIZE} --force

.include <bsd.port.post.mk>
