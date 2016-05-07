# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mupen64plus
PORTVERSION=	2.5
PORTREVISION?=	0
CATEGORIES=	emulators

MAINTAINER?=	acm@FreeBSD.org
COMMENT=	Fork of Mupen64 Nintendo 64 emulator with plugins (meta port)

# Mupen64 Emulator core and ui-console
RUN_DEPENDS+=	${LOCALBASE}/lib/libmupen64plus.so.2:emulators/mupen64plus-core
RUN_DEPENDS+=	mupen64plus:emulators/mupen64plus-ui-console

# Audio plugins
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-audio-sdl.so:emulators/mupen64plus-audio-sdl

# Input plugins
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-input-sdl.so:emulators/mupen64plus-input-sdl

# Graphics plugins
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-rice.so:emulators/mupen64plus-video-rice
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-glide64mk2.so:emulators/mupen64plus-video-glide64mk2

# RSP plugins
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-rsp-hle.so:emulators/mupen64plus-rsp-hle

USES=		metaport

.include <bsd.port.mk>
