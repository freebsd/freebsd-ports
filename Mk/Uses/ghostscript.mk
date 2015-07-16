# $FreeBSD$
#
# Provide support for ghostscript ports.
#
# Feature:	ghostscript
# Usage:	USES=ghostscript or USES=ghostscript:args
# Valid ARGS:	<version>, build, run, nox11, agpl
#
# version 	The chooseable versions are 7, 8 and 9. If no version is
#		specified version 9 is selected.
#
#		USES=ghostscript:7	# Use Ghostscript 7
#		USES=ghostscript:run	# Use the set default Ghostscript as a run dependancy
#		USES=ghostscript:8,build # Use ghostscript 8 as a build dependancy.
#
# nox11		Indicate that the Ghostscript nox11 port is required.
# agpl		Indicate that the Ghostscript apgl port is required.
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
_GS_VERSION=	7 8 9

_GS_ARGS=		${ghostscript_ARGS}

.if ${_GS_ARGS:N[789]:Nnox11:Nagpl:Nbuild:Nrun}
IGNORE=		Unknown ghostscript argument ${_GS_ARGS}
.endif

# Determine version number of Ghostscript to use
.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if ${_GS_VERSION:M${GHOSTSCRIPT_DEFAULT}} == ""
IGNORE=		Invalid GHOSTSCRIPT_DEFAULT value: ${GHOSTSCRIPT_DEFAULT}, please select one of ${_GS_VERSION}
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

_GS_SELECTED=	${GHOSTSCRIPT_DEFAULT}
.if ${_GS_ARGS:M9}
_GS_SELECTED:=		9
.elif ${_GS_ARGS:M8}
_GS_SELECTED:=		8
.elif ${_GS_ARGS:M7}
_GS_SELECTED:=		7
.endif

.undef _GS_AGPL_SUFFIX
.if ${_GS_ARGS:Magpl}
. if ${_GS_SELECTED} == "9"
_GS_AGPL_SUFFIX=	-agpl
. else
IGNORE=		Ghostscript-agpl is only available in version 9
. endif
.endif

.undef _GS_NOX11_SUFFIX
.if ${_GS_ARGS:Mnox11} || defined(WITHOUT_X11)
_GS_NOX11_SUFFIX=	-nox11
.endif

# dependencies
_GS_PORT=	ghostscript${_GS_SELECTED}${_GS_AGPL_SUFFIX}${_GS_NOX11_SUFFIX}

.if defined(_GS_BUILD_DEP)
BUILD_DEPENDS+=	${_GS_PORT}>=0:${PORTSDIR}/print/${_GS_PORT}
.endif
.if defined(_GS_RUN_DEP)
RUN_DEPENDS+=	${_GS_PORT}>=0:${PORTSDIR}/print/${_GS_PORT}
.endif

.endif # _INCLUDE_USES_GHOSTSCRIPT_MK
