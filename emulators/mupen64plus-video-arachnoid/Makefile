PORTREVISION=	0
PKGNAMESUFFIX=	-video-arachnoid

COMMENT=	The arachnoid video plugin for Mupen64plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	5e9ea510648b6e0f233796ae4ecaf99dd88175c0

USES+=		gl
USE_GL=		gl glu
USE_SDL=	#

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo
RELEASE_DATE=	20240714

.include "${MASTERDIR}/Makefile"
