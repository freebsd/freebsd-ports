PORTREVISION=	0
PKGNAMESUFFIX=	-video-glide64

COMMENT=	Glide64 video plugin for Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	713c833826c47e4decd78f6f28a4a1bd8f1527ea

USES+=		gl localbase:ldflags sdl
USE_CXXSTD=	c++14
USE_GL=		gl
USE_SDL=	sdl2

CFLAGS+=	-I${LOCALBASE}/include/${PORTNAME}

MASTERDIR=	${.CURDIR}/../mupen64plus-core

DISTINFO_FILE=		${.CURDIR}/distinfo

OPTIONS_DEFINE=	#

RELEASE_DATE=	20240714

.include "${MASTERDIR}/Makefile"
