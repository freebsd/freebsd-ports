# Provide support for ghostscript ports.
#
# Feature:	ghostscript
# Usage:	USES=ghostscript or USES=ghostscript:args
# Valid ARGS:	<version>, build, run, test, x11
#
# version 	The chooseable versions are 9 and agpl. If no version is
#		specified version agpl is selected.
#
#		USES=ghostscript:9	# Use Ghostscript 9
#		USES=ghostscript:run	# Use the set default Ghostscript as a run dependency
#		USES=ghostscript:9,build # Use ghostscript 9 as a build dependency.
#
# x11		Indicate that X11 support is required.
# build		Indicates that Ghostscript is needed at build time and adds
#		it as BUILD_DEPENDS.
# run		Indicates that Ghostscript is needed at run time and adds
#		it as RUN_DEPENDS.
# test		Indicates that Ghostscript is needed at test time and adds
#		it as TEST_DEPENDS.
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
_GS_VERSION=	9 agpl

_GS_ARGS=		${ghostscript_ARGS}

.  if ${_GS_ARGS:N[9]:Nagpl:Nx11:Nbuild:Nrun:Ntest}
IGNORE?=	Unknown ghostscript argument ${_GS_ARGS}
.  endif

.  if ${GHOSTSCRIPT_DEFAULT:N[9]:Nagpl}
IGNORE?=	Invalid GHOSTSCRIPT_DEFAULT value: ${GHOSTSCRIPT_DEFAULT}, please select one of ${_GS_VERSION}
.  endif

# Make sure that no dependency or some other environment variable
# pollutes the build/run dependency detection
.undef _GS_BUILD_DEP
.undef _GS_RUN_DEP
.undef _GS_TEST_DEP
.  if ${_GS_ARGS:Mbuild}
_GS_BUILD_DEP=	yes
.  endif
.  if ${_GS_ARGS:Mrun}
_GS_RUN_DEP=	yes
.  endif
.  if ${_GS_ARGS:Mtest}
_GS_TEST_DEP=	yes
.  endif

# The port does not specify a build, run, or test dependency, assume that
# a build and run dependency is required.
.  if !defined(_GS_BUILD_DEP) && !defined(_GS_RUN_DEP) && !defined(_GS_TEST_DEP)
_GS_BUILD_DEP=	yes
_GS_RUN_DEP=	yes
.  endif

.undef _GS_SELECTED
.  for V in ${_GS_ARGS} ${GHOSTSCRIPT_DEFAULT}
_V=${V}
.    if ${_V:M9}
_GS_SELECTED?=		9
.    elif ${_V:Magpl}
_GS_SELECTED?=		9-agpl
.    endif
.  endfor

# Resolve minor version number for X11.so library.
.  if !empty(_GS_SELECTED:M9-agpl)
_GS_VERSION_MINOR=	9.16_2
.  elif !empty(_GS_SELECTED:M9)
_GS_VERSION_MINOR=	9.06_11
.  endif

# dependencies
_GS_PORT=	ghostscript${_GS_SELECTED}-base
_GS_X11_PORT=	ghostscript${_GS_SELECTED}-x11

.  for type in BUILD RUN TEST
.    if defined(_GS_${type}_DEP)
${type}_DEPENDS+=	${_GS_PORT}>=${_GS_VERSION_MINOR}:print/${_GS_PORT}
.      if ${_GS_ARGS:Mx11}
${type}_DEPENDS+=	${_GS_X11_PORT}>=${_GS_VERSION_MINOR}:print/${_GS_X11_PORT}
.      endif
.    endif
.  endfor

.endif # _INCLUDE_USES_GHOSTSCRIPT_MK
