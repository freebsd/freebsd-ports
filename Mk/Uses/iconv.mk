# $FreeBSD$
#
# handle dependency on the iconv port
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	iconv
# Usage:	USES=iconv or USES=iconv:ARGS
# Valid ARGS:	lib (default, implicit), build, patch
#
#
.if !defined(_INCLUDE_USES_ICONV_MK)
_INCLUDE_USES_ICONV_MK=	yes

.if !defined(iconv_ARGS)
iconv_ARGS=     lib
.endif

.if !exists(/usr/include/iconv.h)

ICONV_CMD=	${LOCALBASE}/bin/iconv
ICONV_LIB=	-liconv
ICONV_PREFIX=	${LOCALBASE}
ICONV_CONFIGURE_ARG=	--with-libiconv-prefix=${LOCALBASE}
ICONV_CONFIGURE_BASE=	--with-libiconv=${LOCALBASE}

.if ${iconv_ARGS} == "lib"
LIB_DEPENDS+=	libiconv.so.3:${PORTSDIR}/converters/libiconv
.elif ${iconv_ARGS} == "build"
BUILD_DEPENDS+=	${ICONV_CMD}:${PORTSDIR}/converters/libiconv
.elif ${iconv_ARGS} == "patch"
PATCH_DEPENDS+=	${ICONV_CMD}:${PORTSDIR}/converters/libiconv
.endif

.else

ICONV_CMD=	/usr/bin/iconv
ICONV_LIB=
ICONV_PREFIX=	/usr
ICONV_CONFIGURE_ARG=
ICONV_CONFIGURE_BASE=

.endif

.endif
