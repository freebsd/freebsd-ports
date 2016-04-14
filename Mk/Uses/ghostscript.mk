# $FreeBSD$
#
# Provide support for ghostscript ports.
#
# Feature:	ghostscript
# Usage:	USES=ghostscript or USES=ghostscript:args
# Valid ARGS:	<version>, build, run, x11
#
# version 	The chooseable versions are 7, 8, 9 and agpl. If no version is
#		specified version agpl is selected.
#
#		USES=ghostscript:7	# Use Ghostscript 7
#		USES=ghostscript:run	# Use the set default Ghostscript as a run dependancy
#		USES=ghostscript:8,build # Use ghostscript 8 as a build dependancy.
#
# x11		Indicate that X11 support is required.
# build		Indicates that Ghostscript is needed at build time and adds
#		it as BUILD_DEPENDS.
# run		Indicates that Ghostscript is needed at run time and adds
#		it as RUN_DEPENDS.
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
_GS_VERSION=	7 8 9 agpl

_GS_ARGS=		${ghostscript_ARGS}

.if ${_GS_ARGS:N[789]:Nagpl:Nx11:Nbuild:Nrun}
IGNORE?=	Unknown ghostscript argument ${_GS_ARGS}
.endif

# Determine version number of Ghostscript to use
.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if ${GHOSTSCRIPT_DEFAULT:N[789]:Nagpl}
IGNORE?=	Invalid GHOSTSCRIPT_DEFAULT value: ${GHOSTSCRIPT_DEFAULT}, please select one of ${_GS_VERSION}
.endif

# Make sure that no dependency or some other environment variable
# pollutes the build/run dependency detection
.undef _GS_BUILD_DEP
.undef _GS_RUN_DEP
.if ${_GS_ARGS:Mbuild}
_GS_BUILD_DEP=	yes
.endif
.if ${_GS_ARGS:Mrun}
_GS_RUN_DEP=	yes
.endif

# The port does not specify a build or run dependency, assume both are
# required.
.if !defined(_GS_BUILD_DEP) && !defined(_GS_RUN_DEP)
_GS_BUILD_DEP=	yes
_GS_RUN_DEP=	yes
.endif

.undef _GS_SELECTED
.for V in ${_GS_ARGS} ${GHOSTSCRIPT_DEFAULT}
_V=${V}
.if ${_V:M9}
_GS_SELECTED?=		9
.elif ${_V:Magpl}
_GS_SELECTED?=		9-agpl
.elif ${_V:M8}
_GS_SELECTED?=		8
.elif ${_V:M7}
_GS_SELECTED?=		7
.endif
.endfor

# Resolve minor version number for X11.so library.
.if !empty(_GS_SELECTED:M9-agpl)
_GS_VERSION_MINOR=	9.16_2
.elif !empty(_GS_SELECTED:M9)
_GS_VERSION_MINOR=	9.06_11
.elif !empty(_GS_SELECTED:M8)
_GS_VERSION_MINOR=	8.71_19
.elif !empty(_GS_SELECTED:M7)
_GS_VERSION_MINOR=	7.07_32
.endif

# dependencies
_GS_PORT=	ghostscript${_GS_SELECTED}-base
_GS_X11_PORT=	ghostscript${_GS_SELECTED}-x11

.for type in BUILD RUN
.if defined(_GS_${type}_DEP)
${type}_DEPENDS+=	${_GS_PORT}>=${_GS_VERSION_MINOR}:print/${_GS_PORT}
.if ${_GS_ARGS:Mx11}
${type}_DEPENDS+=	${_GS_X11_PORT}>=${_GS_VERSION_MINOR}:print/${_GS_X11_PORT}
.endif
.endif
.endfor

.endif # _INCLUDE_USES_GHOSTSCRIPT_MK
