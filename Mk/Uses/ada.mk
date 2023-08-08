# Establish Ada-capable compiler as a build dependency
# To change default compiler, define ADA_DEFAULT in make.conf
#
# Feature:      ada
# Usage:        USES=ada:ARGS
# Valid ARGS:   [<version>],[run]
#
# version	The chooseable versions are 6 (default) or 12
#
# run		Add run depends
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_ADA_MK)
_INCLUDE_USES_ADA_MK=    yes

_ADA_SUPPORTED=	6 12

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
_ada_version=	6 # default, to be changed when gnat12 becomes self-supporting
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
CC=		gnatmake -f -u
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
