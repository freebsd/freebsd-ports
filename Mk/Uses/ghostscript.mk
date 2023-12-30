# Provide support for ghostscript ports.
#
# Feature:	ghostscript
# Usage:	USES=ghostscript or USES=ghostscript:args
# Valid ARGS:	<version>, build, lib, run, test, x11
#
# version 	The chooseable versions are 10 only. If no version is
#		specified version 10 is selected.
#
#		USES=ghostscript:10	    # Use Ghostscript 10
#		USES=ghostscript:run	# Use to set default Ghostscript as a run dependency
#		USES=ghostscript:10,build # Use Ghostscript 10 as a build dependency.
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
_GS_VERSION=	10

_GS_ARGS=	${ghostscript_ARGS}

.  if ${_GS_ARGS:N10:Nbuild:Nlib:Nrun:Ntest:Nx11}
IGNORE?=	Unknown ghostscript argument ${_GS_ARGS}
.  endif

.  if ${GHOSTSCRIPT_DEFAULT:N10}
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
.    endif
.  endfor

.  if !empty(_GS_SELECTED:M10)
_GS_FULL_VERSION=	10.02.0
.  endif

# dependencies
_GS_LIB=	libgs.so
_GS_PKGNAME=	ghostscript${_GS_SELECTED}
_GS_PORT=	print/ghostscript${_GS_SELECTED}

.  for type in BUILD LIB RUN TEST
.    if defined(_GS_${type}_DEP)
.        if ${type:MLIB}
${type}_DEPENDS+=	${_GS_LIB}:${_GS_PORT}
.        else
${type}_DEPENDS+=	${_GS_PKGNAME}>=${_GS_FULL_VERSION}:${_GS_PORT}
.        endif
.    endif
.  endfor

.endif # _INCLUDE_USES_GHOSTSCRIPT_MK
