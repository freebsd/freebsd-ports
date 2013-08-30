# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gkrellmms
PORTVERSION=	2.1.22
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM XMMS Plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

LATEST_LINK=	gkrellmms2
WRKSRC=		${WRKDIR}/gkrellmms

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmms.so \
		share/locale/da/LC_MESSAGES/gkrellmms.mo \
		share/locale/es/LC_MESSAGES/gkrellmms.mo \
		share/locale/fr/LC_MESSAGES/gkrellmms.mo \
		share/locale/nl/LC_MESSAGES/gkrellmms.mo \
		share/locale/ru/LC_MESSAGES/gkrellmms.mo

USES=		gmake

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins \
		LOCALEDIR=${PREFIX}/share/locale \
		enable_nls=1

OPTIONS_SINGLE=		PLAYER
OPTIONS_SINGLE_PLAYER=	BMP XMMS
OPTIONS_DEFAULT=	XMMS
BMP_DESC=		Use Beep Media Player
XMMS_DESC=		Use XMMS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBMP}
LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player
MAKE_ENV+=	USE_BMP=yes
.elif ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
.endif

.include <bsd.port.mk>
