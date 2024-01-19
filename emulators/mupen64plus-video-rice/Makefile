PORTREVISION=	0
PKGNAMESUFFIX=	-video-rice

COMMENT=	The rice graphics plugin for Mupen64plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	470865c6c64bdb44645faa88eae59cd87ce561b6

USES=		gl
USE_GL=		glu

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

DISTINFO_FILE=	${.CURDIR}/distinfo

RELEASE_DATE=	20230611

.include "${MASTERDIR}/Makefile"
