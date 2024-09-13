PORTREVISION=	0
PKGNAMESUFFIX=	-video-z64

COMMENT=	Low-level RDP plugin for the Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	11f354a65a5b123fa8d18e761d52c2d3280a9333

USES=		gl sdl
USE_GL=		gl glu glew
USE_SDL=	sdl2

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/GL -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo

RELEASE_DATE=	20240714

.include "${MASTERDIR}/Makefile"
