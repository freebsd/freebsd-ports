# handle tar archives
#
# Feature:	tar
# Usage:	USES=tar[:[Z|bz2|bzip2|lz|lzma|tbz|tbz2|tgz|txz|xz|zst|zstd]
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_TAR_MK)
_INCLUDE_USES_TAR_MK=	yes

.  if empty(tar_ARGS)
EXTRACT_SUFX?=	.tar
.  elif ${tar_ARGS} == Z
EXTRACT_SUFX?=	.tar.Z
.  elif ${tar_ARGS} == bz2 || ${tar_ARGS} == bzip2
EXTRACT_SUFX?=	.tar.bz2
.  elif ${tar_ARGS} == lz
EXTRACT_SUFX?=	.tar.lz
.  elif ${tar_ARGS} == lzma
EXTRACT_SUFX?=	.tar.lzma
.  elif ${tar_ARGS} == tbz
EXTRACT_SUFX?=	.tbz
.  elif ${tar_ARGS} == tbz2
EXTRACT_SUFX?=	.tbz2
.  elif ${tar_ARGS} == tgz
EXTRACT_SUFX?=	.tgz
.  elif ${tar_ARGS} == txz
EXTRACT_SUFX?=	.txz
.  elif ${tar_ARGS} == xz
EXTRACT_SUFX?=	.tar.xz
.  elif ${tar_ARGS} == zst || ${tar_ARGS} == zstd
EXTRACT_SUFX?=	.tar.zst
.  else
IGNORE=	Incorrect 'USES+=tar:${tar_ARGS}'
.  endif
.endif
