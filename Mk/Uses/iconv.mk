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

ICONV_CMD=	${LOCALBASE}/bin/iconv

.if !defined(iconv_ARGS)
iconv_ARGS=     lib
.endif

.if ${iconv_ARGS} == "lib"
LIB_DEPENDS+=	libiconv.so.3:${PORTSDIR}/converters/libiconv
.elif ${iconv_ARGS} == "build"
BUILD_DEPENDS+=	${ICONV_CMD}:${PORTSDIR}/converters/libiconv
.elif ${iconv_ARGS} == "patch"
PATCH_DEPENDS+=	${ICONV_CMD}:${PORTSDIR}/converters/libiconv
.endif

.endif
