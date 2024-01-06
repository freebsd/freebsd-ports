PORTREVISION=	0
PKGNAMESUFFIX=	-video-glide64mk2

COMMENT=	Glide64mk2 video plugin for Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core \
		libboost_thread.so:devel/boost-libs

GH_TAGNAME=	d900f2191575e01eb846a1009be71cbc1b413dba

USES+=		gl localbase:ldflags sdl
USE_CXXSTD=	c++14
USE_GL=		gl
USE_SDL=	sdl2

CFLAGS+=	-I${LOCALBASE}/include/${PORTNAME}

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

DISTINFO_FILE=	${.CURDIR}/distinfo

RELEASE_DATE=	20230611

.include "${MASTERDIR}/Makefile"
