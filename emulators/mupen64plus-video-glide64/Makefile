PORTREVISION=	0
PKGNAMESUFFIX=	-video-glide64

COMMENT=	Glide64 video plugin for Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	bdf9f5ca8e381e6c1c824aa70b26ad34f4eeb132

USES+=		gl localbase:ldflags sdl
USE_CXXSTD=	c++14
USE_GL=		gl
USE_SDL=	sdl2

CFLAGS+=	-I${LOCALBASE}/include/${PORTNAME}

MASTERDIR=	${.CURDIR}/../mupen64plus-core

DISTINFO_FILE=		${.CURDIR}/distinfo

OPTIONS_DEFINE=	#

RELEASE_DATE=	20230611

.include "${MASTERDIR}/Makefile"
