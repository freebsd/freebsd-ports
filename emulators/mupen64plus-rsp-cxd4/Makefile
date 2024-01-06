PORTREVISION=	0
PKGNAMESUFFIX=	-rsp-cxd4

COMMENT=	Low-level RSP processor plugin for the Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

USE_GL=		#
USE_SDL=	#

GH_TAGNAME=	0a4e30f56033396e3ba47ec0fdd7acea3522362a

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

USES+=		compiler:c++11-lang
MAKE_ENV+=	SSE=none
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo

RELEASE_DATE=	20230611

.include "${MASTERDIR}/Makefile"
