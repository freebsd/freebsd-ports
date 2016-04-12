# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mupen64plus
PORTVERSION=	2.5
PORTREVISION=	0
CATEGORIES=	emulators
PKGNAMESUFFIX=	-plugins

MAINTAINER?=	acm@FreeBSD.org
COMMENT=	Third party plugins for Mupen64plus

USES=		metaport

OPTIONS_DEFINE=	VIDEO_ARACHNOID VIDEO_GLIDE64 VIDEO_Z64 RSP_Z64 RSP_CXD4
VIDEO_ARACHNOID_DESC=	Arachnoid video plugin
VIDEO_GLIDE64_DESC=	Glide64 video plugin
VIDEO_Z64_DESC=	z64 video plugin
RSP_Z64_DESC=	z64 RSP plugin
RSP_CXD4_DESC=	cxd4 RSP plugin

OPTIONS_DEFAULT=	VIDEO_ARACHNOID VIDEO_GLIDE64 VIDEO_Z64 RSP_Z64 RSP_CXD4

.for OPT in ${OPTIONS_DEFINE}
${OPT}_RUN_DEPENDS=	${LOCALBASE}/lib/${PORTNAME}/mupen64plus-${OPT:tl:S/_/-/}.so:emulators/mupen64plus-${OPT:tl:S/_/-/}
.endfor

.include <bsd.port.mk>
