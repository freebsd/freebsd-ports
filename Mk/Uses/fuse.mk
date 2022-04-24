# Handle dependency on the fuse port
#
# Feature:	fuse
# Usage:	USES=fuse[:version]
# Valid ARGS:	2 [default], 3
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_FUSE_MK)
_INCLUDE_USES_FUSE_MK=	yes

.  if !empty(fuse_ARGS)
LIBFUSE_VER=	${fuse_ARGS}
.  endif
LIBFUSE_VER?=	2

.  if ${LIBFUSE_VER} == 2
LIB_DEPENDS+=	libfuse.so:sysutils/fusefs-libs
.  elif ${LIBFUSE_VER} == 3
LIB_DEPENDS+=	libfuse3.so:sysutils/fusefs-libs3
.  else
IGNORE=		cannot install: unknown FUSE library version: ${LIBFUSE_VERSION}
.  endif

.endif
