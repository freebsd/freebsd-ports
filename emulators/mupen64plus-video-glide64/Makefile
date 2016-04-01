# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-video-glide64
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-src-${PORTVERSION}${EXTRACT_SUFX}:plugin

COMMENT=	Glide64 video plugin for Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

USE_GL=		gl
USE_SDL=	sdl2

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo
EXTRACT_AFTER_ARGS=	#
BUILD_WRKSRC=		${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}/projects/unix
WRKSRC=			${WRKDIR}

.include "${MASTERDIR}/Makefile"
