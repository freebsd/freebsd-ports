# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mupen64plus
PORTVERSION=	2.5
PORTREVISION=	0
CATEGORIES=	emulators
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-plugins
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER?=	acm@FreeBSD.org
COMMENT=	Third party plugins for Mupen64plus

OPTIONS_DEFINE=	VIDEO_ARACHNOID VIDEO_GLIDE64 VIDEO_Z64 RSP_Z64 RSP_CXD4
VIDEO_ARACHNOID_DESC=	Arachnoid video plugin
VIDEO_GLIDE64_DESC=	Glide64 video plugin
VIDEO_Z64_DESC=	z64 video plugin
RSP_Z64_DESC=	z64 RSP plugin
RSP_CXD4_DESC=	cxd4 RSP plugin

OPTIONS_DEFAULT=	VIDEO_ARACHNOID VIDEO_GLIDE64 VIDEO_Z64 RSP_Z64 RSP_CXD4

.include <bsd.port.pre.mk>

# Graphics plugins
.if ${PORT_OPTIONS:MVIDEO_ARACHNOID}
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-arachnoid.so:${PORTSDIR}/emulators/mupen64plus-video-arachnoid
.endif

.if ${PORT_OPTIONS:MVIDEO_GLIDE64}
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-glide64.so:${PORTSDIR}/emulators/mupen64plus-video-glide64
.endif

.if ${PORT_OPTIONS:MVIDEO_Z64}
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-video-z64.so:${PORTSDIR}/emulators/mupen64plus-video-z64
.endif

# RSP plugins
.if ${PORT_OPTIONS:MRSP_Z64}
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-rsp-z64.so:${PORTSDIR}/emulators/mupen64plus-rsp-z64
.endif

.if ${PORT_OPTIONS:MRSP_CXD4}
RUN_DEPENDS+=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-rsp-cxd4.so:${PORTSDIR}/emulators/mupen64plus-rsp-cxd4
.endif

NO_MTREE=	yes
NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.post.mk>
