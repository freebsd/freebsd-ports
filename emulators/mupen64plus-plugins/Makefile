# New ports collection makefile for:    mupen64plus-plugins
# Date created:         2011-12-20
# Whom:                 Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mupen64plus
PORTVERSION=	1.99.4
CATEGORIES=	emulators
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-plugins
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER?=	acm@FreeBSD.org
COMMENT=	Third party plugins for Mupen64plus

OPTIONS=	VIDEO_ARACHNOID		"Arachnoid video plugin"	on \
		VIDEO_GLIDE64		"Glide64 video plugin"	on \
		VIDEO_Z64		"z64 video plugin"	on \
		RSP_Z64			"z64 RSP plugin"	on

.include <bsd.port.pre.mk>
		
# Graphics plugins
.if defined(WITH_VIDEO_ARACHNOID)
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-arachnoid.so:${PORTSDIR}/emulators/mupen64plus-video-arachnoid
.endif

.if defined(WITH_VIDEO_GLIDE64)
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-glide64.so:${PORTSDIR}/emulators/mupen64plus-video-glide64
.endif

.if defined(WITH_VIDEO_Z64)
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-z64.so:${PORTSDIR}/emulators/mupen64plus-video-z64
.endif

# RSP plugins
.if defined(WITH_RSP_Z64)
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-rsp-z64.so:${PORTSDIR}/emulators/mupen64plus-rsp-z64
.endif

NO_MTREE=	yes
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.post.mk>
