# New ports collection makefile for:    mupen64
# Date created:         17.Sep 2004
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.4
CATEGORIES+=	emulators
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	Mupen64 is a Nintendo 64 emulator with plugins

RUN_DEPENDS+=	${LOCALBASE}/bin/mupen64:${PORTSDIR}/${PKGCATEGORY}/mupen64-base
RUN_DEPENDS+=	${PLUGINDIR}/dummyaudio.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-dummyaudio
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_audio.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-sound
RUN_DEPENDS+=	${PLUGINDIR}/jttl_audio.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-sdlaudio
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_input.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-input
RUN_DEPENDS+=	${PLUGINDIR}/blight_input.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-sdlinput
RUN_DEPENDS+=	${PLUGINDIR}/ricedaedalus.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-rice
RUN_DEPENDS+=	${PLUGINDIR}/mupen64_hle_rsp_azimer.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-rsp
RUN_DEPENDS+=	${PLUGINDIR}/Glide64.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-glide
RUN_DEPENDS+=	${PLUGINDIR}/glN64-0.4.1.so:${PORTSDIR}/${PKGCATEGORY}/mupen64-gln64

NO_MTREE=	yes
NO_BUILD=	yes

do-install:	# empty

PLUGINDIR=	${LOCALBASE}/share/mupen64/plugins

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
