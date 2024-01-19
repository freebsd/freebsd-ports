PORTREVISION=	0
PKGNAMESUFFIX=	-video-arachnoid

COMMENT=	The arachnoid video plugin for Mupen64plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	8187d1135ced0102f99d8305b52e0e75b01ef917

USES+=		gl
USE_GL=		gl glu
USE_SDL=	#

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo
RELEASE_DATE=	20230611

.include "${MASTERDIR}/Makefile"
