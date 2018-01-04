# $FreeBSD$
#
# Handle dependency on eigen 
#
# Feature:	eigen
# Usage:	USES=eigen:ARGS
# Valid ARGS:	<version>,[build,run]
#
# version	The chooseable versions are 2 and 3.
#		USES=eigen:2 # Use eigen 2.x
#		USES=eigen:3 # Use eigen 3.x
#
# build		Add build depends [default]
# run		Add run depends
#
# MAINTAINER: kde@FreeBSD.org
#

.if ! defined(_INCLUDE_USES_EIGEN_MK)
_INCLUDE_USES_EIGEN_MK=	YES

_EIGEN_SUPPORTED=	2 3

_eigen_version=	#
.  for _ver in ${_EIGEN_SUPPORTED:O:u}
.    if ${eigen_ARGS:M${_ver}}
.      if empty(_eigen_version)
_eigen_version=	${_ver}
.      else
IGNORE=		Incorrect USES=eigen:${eigen_ARGS} - multiple versions defined
.      endif
.    endif
.  endfor

.  if empty(_eigen_version)
IGNORE=		Incorrect USES=eigen:${eigen_ARGS} - no version defined
.  endif

# Export the version of the chosen eigen port
_EIGEN_PORT=	math/eigen${_eigen_version}
_EIGEN_PATH=	${LOCALBASE}/libdata/pkgconfig/eigen${_eigen_version}.pc
_EIGEN_DEP=	${_EIGEN_PATH}:${_EIGEN_PORT}

# Append the correct BUILD-/RUN_DEPENDS
.  if empty(eigen_ARGS:Mbuild) && empty(eigen_ARGS:Mrun)
eigen_ARGS+=	build
.  endif
.  if ! empty(eigen_ARGS:Mbuild)
BUILD_DEPENDS+=	${_EIGEN_DEP}
.  endif
.  if ! empty(eigen_ARGS:Mrun)
RUN_DEPENDS+=	${_EIGEN_DEP}
.  endif

.endif
