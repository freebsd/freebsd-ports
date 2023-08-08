PORTREVISION=	2
PKGNAMESUFFIX=	-video-glide64
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-src-${PORTVERSION}${EXTRACT_SUFX}:plugin

COMMENT=	Glide64 video plugin for Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

USES+=		gl localbase:ldflags sdl
USE_CXXSTD=	c++14
USE_GL=		gl
USE_SDL=	sdl2

CFLAGS+=	-I${LOCALBASE}/include/${PORTNAME}

MASTERDIR=	${.CURDIR}/../mupen64plus-core
EXTRACT_AFTER_ARGS=	#

BUILD_WRKSRC=		${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}/projects/unix
WRKSRC=			${WRKDIR}

DISTINFO_FILE=		${.CURDIR}/distinfo

OPTIONS_DEFINE=	#

.include "${MASTERDIR}/Makefile"
