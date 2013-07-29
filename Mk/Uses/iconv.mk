# $FreeBSD$
#
# handle dependency on the iconv port
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	iconv
# Usage:	USES=iconv
# Valid ARGS:	does not require args
#
#
.if !defined(_INCLUDE_USES_ICONV_MK)
_INCLUDE_USES_ICONV_MK=	yes

.if defined(iconv_ARGS)
IGNORE=	USES=iconv does not require args
.endif

LIB_DEPENDS+=	libiconv.so.3:${PORTSDIR}/converters/libiconv

.endif
