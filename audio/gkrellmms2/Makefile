# New ports collection makefile for:	gkrellmms
# Date Created:		Jun 22 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmms
PORTVERSION=	2.1.22
PORTREVISION=	1
#PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM XMMS Plugin

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

LATEST_LINK=	gkrellmms2
WRKSRC=		${WRKDIR}/gkrellmms

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmms.so \
		share/locale/da/LC_MESSAGES/gkrellmms.mo \
		share/locale/es/LC_MESSAGES/gkrellmms.mo \
		share/locale/fr/LC_MESSAGES/gkrellmms.mo \
		share/locale/nl/LC_MESSAGES/gkrellmms.mo \
		share/locale/ru/LC_MESSAGES/gkrellmms.mo

USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins \
		LOCALEDIR=${PREFIX}/share/locale \
		enable_nls=1

OPTIONS=	BEEP_MEDIA_PLAYER	"Use beep"	off \
		XMMS			"Use XMMS"	on

.include <bsd.port.pre.mk>

.if !defined(WITH_BEEP_MEDIA_PLAYER) && !defined(WITH_XMMS)
.if defined(WITHOUT_BEEP_MEDIA_PLAYER) && defined(WITHOUT_XMMS)
BROKEN=		"You need to select beep or XMMS.  Run 'make config' again!"
.endif
WITH_XMMS=	yes
.elif defined(WITH_BEEP_MEDIA_PLAYER) && defined(WITH_XMMS)
BROKEN=		"beep and XMMS is mutually exclusive.  Run 'make config' again!"
.endif
.if defined(WITH_BEEP_MEDIA_PLAYER)
LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player
MAKE_ENV+=	USE_BMP=yes
.elif defined(WITH_XMMS)
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
.endif

.include <bsd.port.post.mk>
