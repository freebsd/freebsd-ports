# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	eq
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}u/${PORTNAME}-xmms-src/${PORTVERSION}
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-xmms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time graphical equalizer plugin for XMMS

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
NO_STAGE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Effect/libeq.la \
		lib/xmms/Effect/libeq.so

OPTIONS_DEFINE=	BENCHMARK EXT_INS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	EXT_INS OPTIMIZED_CFLAGS

BENCHMARK_DESC=	Enable counting the cycles used by the IIR
EXT_INS_DESC=	Use MMX/SSE/SSE2 instructions if available

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBENCHMARK}
CONFIGURE_ARGS+=	--enable-benchmark
.endif

.if empty(PORT_OPTIONS:MEXT_INS) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--disable-autodetect
.endif

.if empty(PORT_OPTIONS:MOPTIMIZED_CFLAGS)
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

.include <bsd.port.mk>
