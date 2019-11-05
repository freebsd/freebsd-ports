# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-video-arachnoid
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-src-${PORTVERSION}${EXTRACT_SUFX}:plugin

COMMENT=	The arachnoid video plugin for Mupen64plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

USES+=		gl
USE_GL=		gl glu
USE_SDL=	#

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo
EXTRACT_AFTER_ARGS=	#
BUILD_WRKSRC=		${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}/projects/unix
WRKSRC=			${WRKDIR}

.include "${MASTERDIR}/Makefile"
