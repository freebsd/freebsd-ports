# $FreeBSD$
#
# handle dependency on the iconv port
#
# Feature:	iconv
# Usage:	USES=iconv or USES=iconv:ARGS
# Valid ARGS:	lib (default, implicit), build, patch,
#		wchar_t (port uses "WCHAR_T" extension),
#		translit (port uses "//TRANSLIT" extension)
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_ICONV_MK)
_INCLUDE_USES_ICONV_MK=	yes

iconv_ARGS:=	${iconv_ARGS:S/,/ /g}

.if !exists(/usr/include/iconv.h) || ${iconv_ARGS:Mwchar_t} || ${iconv_ARGS:Mtranslit}

ICONV_CMD=	${LOCALBASE}/bin/iconv
ICONV_LIB=	-liconv
ICONV_PREFIX=	${LOCALBASE}
ICONV_CONFIGURE_ARG=	--with-libiconv-prefix=${LOCALBASE}
ICONV_CONFIGURE_BASE=	--with-libiconv=${LOCALBASE}

.if ${iconv_ARGS:Mbuild}
BUILD_DEPENDS+=	${ICONV_CMD}:${PORTSDIR}/converters/libiconv
.elif ${iconv_ARGS:Mpatch}
PATCH_DEPENDS+=	${ICONV_CMD}:${PORTSDIR}/converters/libiconv
.else
LIB_DEPENDS+=	libiconv.so.3:${PORTSDIR}/converters/libiconv
.endif

.else

ICONV_CMD=	/usr/bin/iconv
ICONV_LIB=
ICONV_PREFIX=	/usr
ICONV_CONFIGURE_ARG=
ICONV_CONFIGURE_BASE=

.if exists(${LOCALBASE}/include/iconv.h)
CPPFLAGS+=	-DLIBICONV_PLUG
CFLAGS+=	-DLIBICONV_PLUG
CXXFLAGS+=	-DLIBICONV_PLUG
.endif

.endif

.endif
