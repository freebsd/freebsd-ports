# handle minizip version
#
# Feature:	minizip
# Usage:	USES=minizip[:ng]
#
# MAINTAINER: lbartoletti@FreeBSD.org

.if !defined(_INCLUDE_USES_MINIZIP_MK)
_INCLUDE_USES_MINIZIP_MK=	yes

.  if empty(minizip_ARGS)
LIB_DEPENDS+=		libminizip.so:archivers/minizip
.  elif ${minizip_ARGS} == "ng"
LIB_DEPENDS+=		libminizip-ng.so:archivers/minizip-ng
.  else
IGNORE=	Incorrect 'USES+=minizip:${minizip_ARGS}' expecting 'USES+=minizip[:ng]'
.  endif

.endif
