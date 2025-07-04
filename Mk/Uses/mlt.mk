# Handle dependency on mlt
#
# Feature:	mlt
# Usage:	USES=mlt:ARGS
# Valid ARGS:	<version>,nodepend
#
# version	The only currently supported version is 7.
#		USES=mlt:7 # Use mlt 7.x
# nodepend	If nodepend is set, no LIB_DEPENDS line
#		will be generated (useful for the mlt-ports)
#
# MAINTAINER: kde@FreeBSD.org
#

.if ! defined(_INCLUDE_USES_MLT_MK)
_INCLUDE_USES_MLT_MK=	YES

_MLT_SUPPORTED=	7

_mlt_version=	#
.  for _ver in ${_MLT_SUPPORTED:O:u}
.    if ${mlt_ARGS:M${_ver}}
.      if empty(_mlt_version)
_mlt_version=	${_ver}
.      else
IGNORE=		Incorrect USES=mlt:${mlt_ARGS} - multiple versions defined
.      endif
.    endif
.  endfor

.  if empty(_mlt_version)
IGNORE=		Incorrect USES=mlt:${mlt_ARGS} - no version defined (valid: ${_MLT_SUPPORTED})
.  endif

.  if ! empty(mlt_ARGS:Mnodepend)
_MLT_NODEPEND=	yes
.  endif

# Library dependencies
_MLT7_VERSION=	7.32.0
_MLT7_PORTNAME=	mlt7
_MLT7_LIB=	libmlt-7.so
_MLT7_MELT=	${LOCALBASE}/bin/melt-7

# Export the version of the chosen mlt port
_MLT_VERSION=	${_MLT${_mlt_version}_VERSION}
_MLT_PORTNAME=	${_MLT${_mlt_version}_PORTNAME}
_MLT_PORT=	multimedia/${_MLT_PORTNAME}
_MLT_LIB=	${_MLT${_mlt_version}_LIB}
_MLT_DEP=	${_MLT_LIB}:${_MLT_PORT}
_MLT_MELT=	${_MLT${_mlt_version}_MELT}

# Append the correct LIB_DEPENDS
.  if !defined(_MLT_NODEPEND)
LIB_DEPENDS+=	${_MLT_DEP}
.  endif

# Append version to PLIST_SUB
PLIST_SUB+=	MLT_VERSION=${_MLT_VERSION}

.endif
