PORTREVISION=	0
PKGNAMESUFFIX=	-video-z64

COMMENT=	Low-level RDP plugin for the Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	e8023148574d44fbabd1bb9d0ded7192869ec2ce

USES=		gl sdl
USE_GL=		gl glu glew
USE_SDL=	sdl2

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/GL -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo

RELEASE_DATE=	20230611

.include "${MASTERDIR}/Makefile"
