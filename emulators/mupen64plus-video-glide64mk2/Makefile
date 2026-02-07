PORTREVISION=	5
PKGNAMESUFFIX=	-video-glide64mk2

COMMENT=	Glide64mk2 video plugin for Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core \
		libboost_thread.so:devel/boost-libs

GH_TAGNAME=	2e2704194a6a188c8e5127970e9aa320f37e5156

USES+=		gl localbase:ldflags sdl
USE_CXXSTD=	c++17
USE_GL=		gl
USE_SDL=	sdl2

CFLAGS+=	-I${LOCALBASE}/include/${PORTNAME}

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

DISTINFO_FILE=	${.CURDIR}/distinfo

RELEASE_DATE=	20240714

.include "${MASTERDIR}/Makefile"
