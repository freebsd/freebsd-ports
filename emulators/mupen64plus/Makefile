# New ports collection makefile for:    mupen64plus
# Date created:         2008-05-17
# Whom:                 Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mupen64plus
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER?=	acm@FreeBSD.org
COMMENT=	A fork of Mupen64 Nintendo 64 emulator with plugins (meta port)

# Mupen64 Emulator gui and no-gui
RUN_DEPENDS+=	${LOCALBASE}/bin/mupen64plus:${PORTSDIR}/emulators/mupen64plus-base

# Audio plugins
RUN_DEPENDS+=	${PLUGINDIR}/dummyaudio.so:${PORTSDIR}/emulators/mupen64plus-dummyaudio
RUN_DEPENDS+=	${PLUGINDIR}/jttl_audio.so:${PORTSDIR}/emulators/mupen64plus-sdlaudio

# Input plugins
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_input.so:${PORTSDIR}/emulators/mupen64plus-input
RUN_DEPENDS+=	${PLUGINDIR}/blight_input.so:${PORTSDIR}/emulators/mupen64plus-sdlinput
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_hle_rsp_azimer.so:${PORTSDIR}/emulators/mupen64plus-rsp

# Graphics plugins
RUN_DEPENDS+=	${PLUGINDIR}/dummyvideo.so:${PORTSDIR}/emulators/mupen64plus-dummyvideo
RUN_DEPENDS+=	${PLUGINDIR}/ricevideo.so:${PORTSDIR}/emulators/mupen64plus-rice
RUN_DEPENDS+=	${PLUGINDIR}/glide64.so:${PORTSDIR}/emulators/mupen64plus-glide
RUN_DEPENDS+=	${PLUGINDIR}/glN64.so:${PORTSDIR}/emulators/mupen64plus-gln64

NO_MTREE=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLUGINDIR=	${LOCALBASE}/share/mupen64plus/plugins

do-install:	# empty

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
