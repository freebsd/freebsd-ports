# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	18
PKGNAMESUFFIX=	-video-glide64mk2

COMMENT=	Glide64mk2 video plugin for Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core \
		libboost_thread.so:devel/boost-libs

USES+=		gl sdl
USE_GL=		gl
USE_SDL=	sdl2

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

.include "${MASTERDIR}/Makefile"
