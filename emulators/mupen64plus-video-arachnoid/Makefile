# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
PKGNAMESUFFIX=	-video-arachnoid
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-src-${PORTVERSION}${EXTRACT_SUFX}:plugin

COMMENT=	The arachnoid video plugin for Mupen64plus

LIB_DEPENDS=	mupen64plus.2:${PORTSDIR}/emulators/mupen64plus-core

USE_GL=		gl glu
USE_SDL=	#

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

EXTRACT_AFTER_ARGS=	#
BUILD_WRKSRC=		${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}/projects/unix
WRKSRC=			${WRKDIR}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
