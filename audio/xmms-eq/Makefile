# New ports collection makefile for:	xmms-eq
# Date created:			13 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	eq
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}u/${PORTNAME}-xmms-src/${PORTVERSION}
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-xmms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A realtime graphical equalizer plugin for XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Effect/libeq.la \
		lib/xmms/Effect/libeq.so

OPTIONS=	BENCHMARK "Enable counting the cycles used by the IIR" off \
		EXT_INS "Use MMX/SSE/SSE2 instructions if available" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

.if defined(WITH_BENCHMARK)
CONFIGURE_ARGS+=	--enable-benchmark
.endif

.if defined(WITHOUT_EXT_INS) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--disable-autodetect
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
post-patch:
	@${REINPLACE_CMD} -e 's|-O3||g; \
		s|-fomit-frame-pointer||g; \
		s|-finline-functions||g; \
		s|-ffast-math||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
