# $FreeBSD$

PORTNAME=	mupen64
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER?=	acm@FreeBSD.org
COMMENT=	Mupen64 is a Nintendo 64 emulator with plugins (meta port)

# Mupen64 Emulator gui and no-gui
RUN_DEPENDS+=	${LOCALBASE}/bin/mupen64:${PORTSDIR}/emulators/mupen64-base

# Audio plugins
RUN_DEPENDS+=	${PLUGINDIR}/dummyaudio.so:${PORTSDIR}/emulators/mupen64-dummyaudio
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_audio.so:${PORTSDIR}/emulators/mupen64-sound
RUN_DEPENDS+=	${PLUGINDIR}/jttl_audio.so:${PORTSDIR}/emulators/mupen64-sdlaudio

# Input plugins
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_input.so:${PORTSDIR}/emulators/mupen64-input
RUN_DEPENDS+=	${PLUGINDIR}/blight_input.so:${PORTSDIR}/emulators/mupen64-sdlinput
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_hle_rsp_azimer.so:${PORTSDIR}/emulators/mupen64-rsp

# Graphics plugins
RUN_DEPENDS+=	${PLUGINDIR}/ricedaedalus.so:${PORTSDIR}/emulators/mupen64-rice
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_soft_gfx.so:${PORTSDIR}/emulators/mupen64-softgfx
RUN_DEPENDS+=	${PLUGINDIR}/Glide64.so:${PORTSDIR}/emulators/mupen64-glide
RUN_DEPENDS+=	${PLUGINDIR}/glN64.so:${PORTSDIR}/emulators/mupen64-gln64
RUN_DEPENDS+=	${PLUGINDIR}/tr64gl.so:${PORTSDIR}/emulators/mupen64-tr64

NO_MTREE=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLUGINDIR=	${LOCALBASE}/share/mupen64/plugins

do-install:	# empty

NO_STAGE=	yes

DEPRECATED=	Use mupen64plus instead
EXPIRATION_DATE=2014-04-23

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
