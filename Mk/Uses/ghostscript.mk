# Provide support for ghostscript ports.
#
# Feature:	ghostscript
# Usage:	USES=ghostscript or USES=ghostscript:args
# Valid ARGS:	<version>, build, lib, run, test, x11
#
# version 	The chooseable versions are 9, agpl and 10. If no version is
#		specified version agpl is selected. 9 and agpl are synonymous.
#
#		USES=ghostscript:9	# Use Ghostscript 9
#		USES=ghostscript:run	# Use the set default Ghostscript as a run dependency
#		USES=ghostscript:9,build # Use ghostscript 9 as a build dependency.
#
# build		Ghostscript is used as BUILD_DEPENDS
# lib		Ghostscript is used as LIB_DEPENDS
# run		Ghostscript is used as RUN_DEPENDS
# test		Ghostscript is used as TEST_DEPENDS
#
# x11		Indicate that X11 support is required.
#
# If build and run are omitted, Ghostscript will be added as BUILD_DEPENDS and
# RUN_DEPENDS.
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_GHOSTSCRIPT_MK)
_INCLUDE_USES_GHOSTSCRIPT_MK=	yes

# allowed versions
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
_GS_VERSION=	9 agpl 10

_GS_ARGS=	${ghostscript_ARGS}

.  if ${_GS_ARGS:N9:N10:Nagpl:Nbuild:Nlib:Nrun:Ntest:Nx11}
IGNORE?=	Unknown ghostscript argument ${_GS_ARGS}
.  endif

.  if ${GHOSTSCRIPT_DEFAULT:N9:Nagpl:N10}
IGNORE?=	Invalid GHOSTSCRIPT_DEFAULT value: ${GHOSTSCRIPT_DEFAULT}, please select one of ${_GS_VERSION}
.  endif

# Make sure that no dependency or some other environment variable
# pollutes the build/run dependency detection
.undef _GS_BUILD_DEP
.undef _GS_LIB_DEP
.undef _GS_RUN_DEP
.undef _GS_TEST_DEP
.  if ${_GS_ARGS:Mbuild}
_GS_BUILD_DEP=	yes
.  endif
.  if ${_GS_ARGS:Mlib}
_GS_LIB_DEP=	yes
.  endif
.  if ${_GS_ARGS:Mrun}
_GS_RUN_DEP=	yes
.  endif
.  if ${_GS_ARGS:Mtest}
_GS_TEST_DEP=	yes
.  endif

# The port does not specify a build, lib, run or test dependency, assume that
# a build and run dependency is required.
.  if !defined(_GS_BUILD_DEP) && !defined(_GS_LIB_DEP) && !defined(_GS_RUN_DEP) && !defined(_GS_TEST_DEP)
_GS_BUILD_DEP=	yes
_GS_RUN_DEP=	yes
.  endif

.undef _GS_SELECTED
.  for V in ${_GS_ARGS} ${GHOSTSCRIPT_DEFAULT}
_V=${V}
.    if ${_V:M10}
_GS_SELECTED?=		10
.    elif ${_V:M9}
_GS_SELECTED?=		9-agpl
.    elif ${_V:Magpl}
_GS_SELECTED?=		9-agpl
.    endif
.  endfor

.  undef _GS_FLAVORED
.  if empty(_GS_SELECTED:M9-agpl)
_GS_FLAVORED=	yes
.  endif

# Resolve minor version number for X11.so library.
.  if !empty(_GS_SELECTED:M10)
_GS_VERSION_MINOR=	10.01.2
.  elif !empty(_GS_SELECTED:M9-agpl)
_GS_VERSION_MINOR=	9.56.1
.  endif

# dependencies
_GS_LIB=	libgs.so
_GS_PKGNAME=	ghostscript${_GS_SELECTED}${_GS_FLAVORED:?:-base}
_GS_X11_PKGNAME=ghostscript${_GS_SELECTED}-x11
_GS_PORT=	print/ghostscript${_GS_SELECTED}${_GS_FLAVORED:?:-base}
_GS_X11_PORT=	print/ghostscript${_GS_SELECTED}${_GS_FLAVORED:?@:-}x11

.  for type in BUILD LIB RUN TEST
.    if defined(_GS_${type}_DEP)
.      if !defined(_GS_FLAVORED) || !${_GS_ARGS:Mx11}
.        if ${type:MLIB}
${type}_DEPENDS+=	${_GS_LIB}:${_GS_PORT}
.        else
${type}_DEPENDS+=	${_GS_PKGNAME}>=${_GS_VERSION_MINOR}:${_GS_PORT}
.        endif
.      endif
.      if ${_GS_ARGS:Mx11}
.        if ${type:MLIB}
${type}_DEPENDS+=	${_GS_LIB}:${_GS_X11_PORT}
.        else
${type}_DEPENDS+=	${_GS_X11_PKGNAME}>=${_GS_VERSION_MINOR}:${_GS_X11_PORT}
.        endif
.      endif
.    endif
.  endfor

.endif # _INCLUDE_USES_GHOSTSCRIPT_MK
