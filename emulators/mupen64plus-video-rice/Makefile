PORTREVISION=	0
PKGNAMESUFFIX=	-video-rice

COMMENT=	The rice graphics plugin for Mupen64plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	fcf00779f08a9503ef30d26422f6b0350684820d

USES=		gl
USE_GL=		glu

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

DISTINFO_FILE=	${.CURDIR}/distinfo

RELEASE_DATE=	20240714

.include "${MASTERDIR}/Makefile"
