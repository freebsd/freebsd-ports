PORTREVISION=	0
PKGNAMESUFFIX=	-rsp-cxd4

COMMENT=	Low-level RSP processor plugin for the Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:emulators/mupen64plus-core

USE_GL=		#
USE_SDL=	#

GH_TAGNAME=	f6ff3719cb68d3e1c1497fc87a661921671db719

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

USES+=		compiler:c++11-lang
MAKE_ENV+=	SSE=none
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

DISTINFO_FILE=		${.CURDIR}/distinfo

RELEASE_DATE=	20240714

.include "${MASTERDIR}/Makefile"
