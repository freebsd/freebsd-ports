# New ports collection makefile for:	mupen64plus-video-z64
# Date created:		2011-12-20
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-video-z64
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-src-${PORTVERSION}${EXTRACT_SUFX}:plugin

COMMENT=	Low-level RDP plugin for the Mupen64Plus

LIB_DEPENDS=	mupen64plus.2:${PORTSDIR}/emulators/mupen64plus-core

USE_GL=		gl glu glew
USE_SDL=	yes

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
BUILD_WRKSRC=		${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}/projects/unix
WRKSRC=			${WRKDIR}

.include "${MASTERDIR}/Makefile"
