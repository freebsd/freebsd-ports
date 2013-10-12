# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gkrellmms
PORTVERSION=	2.1.22
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/
PKGNAMESUFFIX=	2

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM XMMS Plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellmms

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmms.so \
		share/locale/da/LC_MESSAGES/gkrellmms.mo \
		share/locale/es/LC_MESSAGES/gkrellmms.mo \
		share/locale/fr/LC_MESSAGES/gkrellmms.mo \
		share/locale/nl/LC_MESSAGES/gkrellmms.mo \
		share/locale/ru/LC_MESSAGES/gkrellmms.mo

USES=		gmake pkgconfig

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins \
		LOCALEDIR=${PREFIX}/share/locale \
		enable_nls=1

OPTIONS_SINGLE=		PLAYER
OPTIONS_SINGLE_PLAYER=	BMP XMMS
OPTIONS_DEFAULT=	XMMS
BMP_DESC=		Use Beep Media Player
BMP_LIB_DEPENDS=	libbeep.so:${PORTSDIR}/multimedia/beep-media-player
BMP_MAKE_ENV=		USE_BMP=yes
XMMS_DESC=		Use XMMS
XMMS_LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
