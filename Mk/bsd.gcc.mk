#-*- tab-width: 4; -*-
# ex:ts=4
#
# bsd.gcc.mk - Support for smarter USE_GCC usage.
#
#
# To request the use of a current version of GCC, specify USE_GCC=yes in
# your port/system configuration.  This is the preferred use of USE_GCC.
# It uses the canonical version of GCC defined in bsd.default-versions.mk.
#
# If your port needs a specific version of GCC, you can instead specify
# that using USE_GCC=X (where X is the version of GCC).
#
# Optionally comma-separated arguments follow the version specifier.
# Currently we support:
#   build ... which adds GCC as a build dependency (BUILD_DEPENDS) only.
#
# If no arguments are specified, GCC is added as both a build dependency
# and a run time dependency.
#
#
# Examples:
#   USE_GCC=	yes			# port requires a current version of GCC
#							# as defined in bsd.default-versions.mk.
#   USE_GCC=	11 			# port requires GCC 11.
#   USE_GCC=	yes:build	# port requires a current version of GCC at
#							# build time only.
#   USE_GCC=	10:build	# port requires GCC 10 at build time only.
#
# If you are wondering what your port exactly does, use "make test-gcc"
# to see some debugging.

GCC_Include_MAINTAINER=		gerald@FreeBSD.org

# All GCC versions supported by this framework.
#
# When updating this, keep Mk/bsd.default-versions.mk in sync.
GCCVERSIONS=	4.8 9 10 11 12 13 14

# No configurable parts below this. ####################################
#

# Split arguments
.if defined(USE_GCC)
__USE_GCC:=		${USE_GCC:C/\:.*//}
_USE_GCC_ARGS:=	${USE_GCC:C/^[^\:]*(\:|\$)//:S/,/ /g}
USE_GCC=		${__USE_GCC}
.endif

.if ${_USE_GCC_ARGS:Mbuild}
_USE_GCC_ARGS:=		${_USE_GCC_ARGS:Nbuild}
.else
_USE_GCC_RUN_DEPENDS=	yes
.endif

.if !empty(_USE_GCC_ARGS)
IGNORE=	bad target specification in USE_GCC; only "build" is supported
.endif

.if defined(USE_GCC) && !defined(FORCE_BASE_CC_FOR_TESTING)

# Handle USE_GCC=yes.
.  if ${USE_GCC} == yes
USE_GCC=	${GCC_DEFAULT}
.  endif

_USE_GCC:=	${USE_GCC}

# See whether we have the specific version requested installed already
# and save that into _GCC_FOUND.  In parallel, check if USE_GCC refers
# to a valid version to begin with.
.  for v in ${GCCVERSIONS}
.    if ${_USE_GCC} == ${v}
_GCCVERSION_OKAY=	true
.      if exists(${LOCALBASE}/bin/gcc${v:S/.//})
_GCC_FOUND:=		${_USE_GCC}
.      endif
.    endif
.  endfor

.  if !defined(_GCCVERSION_OKAY)
IGNORE=	Unknown version of GCC specified (USE_GCC=${USE_GCC})
.  endif

# A concrete version has been selected. Set proper ports dependencies,
# CC, CXX, CPP, and flags.
V:=			${_USE_GCC:S/.//}
.  if ${V} == 14
_GCC_PORT:=		gcc${V}-devel
.  else
_GCC_PORT:=		gcc${V}
.  endif
CC:=			gcc${V}
CXX:=			g++${V}
CPP:=			cpp${V}
_GCC_RUNTIME:=		${LOCALBASE}/lib/gcc${V}
.  if ${PORTNAME} == gcc
# We don't want the rpath stuff while building GCC itself
# so we do not set the FLAGS as done in the else part.
# When building a GCC, we want the target libraries to be used and not the
# host GCC libraries.
.  else
CFLAGS+=		-Wl,-rpath=${_GCC_RUNTIME}
CXXFLAGS+=		-Wl,-rpath=${_GCC_RUNTIME}
LDFLAGS+=		-Wl,-rpath=${_GCC_RUNTIME} -L${_GCC_RUNTIME}
.  endif
.undef V

# Now filter unsupported flags for CC and CXX.
CFLAGS:=		${CFLAGS:N-mretpoline}
CXXFLAGS:=		${CXXFLAGS:N-mretpoline}

BUILD_DEPENDS+=	${CC}:lang/${_GCC_PORT}
.  if defined(_USE_GCC_RUN_DEPENDS)
RUN_DEPENDS+=	${CC}:lang/${_GCC_PORT}
.  endif

# GCC ports already depend on binutils; make sure whatever we build
# leverages this as well.
USE_BINUTILS=	yes

.endif # defined(_USE_GCC) && !defined(FORCE_BASE_CC_FOR_TESTING)


test-gcc:
	@echo USE_GCC=${USE_GCC}
.if defined(IGNORE)
	@echo "IGNORE: ${IGNORE}"
.else
.  if defined(USE_GCC)
	@echo Using GCC version ${_USE_GCC}
.  endif
	@echo CC=${CC} - CXX=${CXX} - CPP=${CPP}
	@echo CFLAGS=\"${CFLAGS}\"
	@echo CXXFLAGS=\"${CXXFLAGS}\"
	@echo LDFLAGS=\"${LDFLAGS}\"
.endif
