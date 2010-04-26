# New ports collection makefile for:   libjpeg-turbo
# Date created:		2010-04-09
# Date modified:	2010-04-12
# Whom:			Denis Podolskiy bytestore@yandex.ru (based on D. R. Commander)
#
# $FreeBSD$
#

PORTNAME=	libjpeg-turbo
PORTVERSION=	0.0.92
CATEGORIES=	graphics
MASTER_SITES=	http://openmoko.spb.ru/repository/ \
		http://mesh.dl.sourceforge.net/project/libjpeg-turbo/${PORTVERSION}/ \
		${MASTER_SITE_XCONTRIB}

MAINTAINER=	bytestore@yandex.ru
COMMENT=	Uses MMX, SSE, and SSE2 to accelerate baseline JPEG (de)compression

ONLY_FOR_ARCH=	amd64 i386
USE_AUTOTOOLS=	autoconf:262 automake:19 libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

BUILD_DEPENDS+=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm:install

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS=	--host x86_64-unknown-freebsd
.elif ${ARCH} == i386
CONFIGURE_ARGS=	--host i386-unknown-freebsd
.endif

pre-configure:
	@${ECHO_CMD} configure jpeg-turbo library
	@cd ${WRKDIR}/libjpeg-turbo-${PORTVERSION} && ${AUTORECONF} -fiv && ${LIBTOOLIZE} --force

.include <bsd.port.post.mk>
