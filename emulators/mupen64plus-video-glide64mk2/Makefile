# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-video-glide64mk2

COMMENT=	Glide64mk2 video plugin for Mupen64Plus

LIB_DEPENDS=	mupen64plus.2:${PORTSDIR}/emulators/mupen64plus-core \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs

USE_GL=		gl
USE_SDL=	yes

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes

.include "${MASTERDIR}/Makefile"
