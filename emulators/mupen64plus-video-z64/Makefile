# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-video-z64
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-src-${PORTVERSION}.0${EXTRACT_SUFX}:plugin

COMMENT=	Low-level RDP plugin for the Mupen64Plus

BROKEN=		Fails to build

LIB_DEPENDS=	libmupen64plus.so.2:${PORTSDIR}/emulators/mupen64plus-core

USE_GL=		gl glu glew
USE_SDL=	yes

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

EXTRACT_AFTER_ARGS=	#
BUILD_WRKSRC=		${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}/projects/unix
WRKSRC=			${WRKDIR}

.include "${MASTERDIR}/Makefile"
