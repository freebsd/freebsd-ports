# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mupen64plus
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Fork of Mupen64 Nintendo 64 emulator with plugins (meta port)

# Mupen64 Emulator core and ui-console
RUN_DEPENDS+=	${LOCALBASE}/lib/libmupen64plus.so.2:${PORTSDIR}/emulators/mupen64plus-core
RUN_DEPENDS+=	mupen64plus:${PORTSDIR}/emulators/mupen64plus-ui-console

# Audio plugins
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-audio-sdl.so:${PORTSDIR}/emulators/mupen64plus-audio-sdl

# Input plugins
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-input-sdl.so:${PORTSDIR}/emulators/mupen64plus-input-sdl

# Graphics plugins
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-rice.so:${PORTSDIR}/emulators/mupen64plus-video-rice
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-glide64mk2.so:${PORTSDIR}/emulators/mupen64plus-video-glide64mk2

# RSP plugins
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-rsp-hle.so:${PORTSDIR}/emulators/mupen64plus-rsp-hle

NO_MTREE=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:	# empty

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
