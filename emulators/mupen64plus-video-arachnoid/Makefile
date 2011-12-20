# New ports collection makefile for:	mupen64plus-video-arachnoid
# Date created:		2011-12-20
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-video-arachnoid
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-src-${PORTVERSION}${EXTRACT_SUFX}:plugin

COMMENT=	The arachnoid video plugin for Mupen64plus

LIB_DEPENDS=	mupen64plus.2:${PORTSDIR}/emulators/mupen64plus-core

USE_GL=		gl glu
USE_SDL=	#

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
BUILD_WRKSRC=		${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}/projects/unix
WRKSRC=			${WRKDIR}

.include "${MASTERDIR}/Makefile"
