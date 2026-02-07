PORTREVISION=	0
PKGNAMESUFFIX=	-rsp-z64

COMMENT=	Low-level RSP processor plugin for the Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

GH_TAGNAME=	1484988bec32ab567dc205b8fd9ff6482d5e5950

USE_GL=		#
USE_SDL=	#

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo
RELEASE_DATE=	20240714

.include "${MASTERDIR}/Makefile"
