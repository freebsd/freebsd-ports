# handle dependency on the libarchive port
#
# Feature:	libarchive
# Usage:	USES=libarchive
# Valid ARGS:	none
#
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_LIBARCHIVE_MK)
_INCLUDE_USES_LIBARCHIVE_MK=	yes
_USES_POST+=	localbase

LIB_DEPENDS+=	libarchive.so.13:archivers/libarchive
.endif
