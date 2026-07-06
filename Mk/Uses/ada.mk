# Establish Ada-capable compiler as a build or run dependency
#
# Feature:      ada
# Usage:        USES=ada:ARGS
# Valid ARGS:   [<version>],[run]
#
# version	If a Port requires a specific version of Ada, it can be
# 		explicitly configured with one of the following versions:
# 		6, 12 (default), 13, 14, or 15
#
# run		Add run depends
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_ADA_MK)
_INCLUDE_USES_ADA_MK=    yes

_ADA_SUPPORTED=	6 12 13 14 15

_ada_version=	#
.  for _ver in ${_ADA_SUPPORTED:O:u}
.    if ${ada_ARGS:M${_ver}}
.      if empty(_ada_version)
_ada_version=	${_ver}
.      else
IGNORE=		Incorrect USES=ada:${ada_ARGS} - multiple versions defined
.      endif
.    endif
.  endfor

.  if empty(_ada_version)
_ada_version=	12 # default
.  endif

.  if ${_ada_version} == 6
_ADAPATH=	${LOCALBASE}/gcc6-aux/bin
_ADAPORT=	lang/gcc6-aux
_BINDEP=	${_ADAPATH}/ada
CC=		ada
.  else
_ADAPATH=	${LOCALBASE}/gnat${_ada_version}/bin
_ADAPORT=	lang/gnat${_ada_version}
_BINDEP=	${_ADAPATH}/gnat
GNATMAKE=	gnatmake -f -u
CC=		gcc
BINARY_ALIAS+=	ada=${_ADAPATH}/gcc
.  endif

.  if ${ada_ARGS:Mrun}
RUN_DEPENDS+=	${_BINDEP}:${_ADAPORT}
.  endif

BUILD_DEPENDS+=	${_BINDEP}:${_ADAPORT}
MAKE_ENV+=	PATH=${_ADAPATH}:${PATH} \
		ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat
CONFIGURE_ENV+=	PATH=${_ADAPATH}:${PATH} \
		ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat

.endif
