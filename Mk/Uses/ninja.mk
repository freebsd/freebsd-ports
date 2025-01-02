# Support for the Ninja and Samurai build systems
#
# Feature:	ninja
# Usage:	USES=ninja[:arg]
# Valid ARGS:	build, make, run, samurai
#
# build		add a build dependency on ninja
# make		use ninja for the build instead of make; implies "build" (default)
# run		add a run dependency on ninja
# samurai	use samurai regardless of NINJA_DEFAULT; implies "make"
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_NINJA_MK)
_INCLUDE_USES_NINJA_MK=	yes

_valid_ARGS=	build make run samurai

.  for _arg in ${ninja_ARGS}
.    if empty(_valid_ARGS:M${_arg})
IGNORE=	'USES+= ninja:${ninja_ARGS}' usage: argument [${_arg}] is not recognized
.    endif
.  endfor

.  if empty(ninja_ARGS)
ninja_ARGS+=	make
.  elif !empty(ninja_ARGS:Msamurai)
_SAMURAI_FROM_ARGS=     yes
ninja_ARGS+=	make
.  endif

.  if ${ninja_ARGS:Mmake}
ninja_ARGS+=	build
.  endif

.  if ${NINJA_DEFAULT} == ninja && !defined(_SAMURAI_FROM_ARGS)
NINJA_CMD=	ninja
_NINJA_PORT=	devel/ninja
.  elif ${NINJA_DEFAULT} == samurai || defined(_SAMURAI_FROM_ARGS)
NINJA_CMD=	samu
_NINJA_PORT=	devel/samurai
MAKE_ENV+=	SAMUFLAGS="-v -j${MAKE_JOBS_NUMBER}"
.    if ${ninja_ARGS:Mbuild} && !${BINARY_ALIAS:U:Mninja=*}
# CMake and Meson have native support for Samurai and use it in lieu of
# Ninja if not found in the build environment. BINARY_ALIAS is needed
# for other ports that call the ninja binary directly with no fallback
# consideration for samu.
BINARY_ALIAS+=	ninja=samu
.    endif
.  else
IGNORE=	invalid DEFAULT_VERSIONS+=ninja=${NINJA_DEFAULT}
.  endif

.  if ${ninja_ARGS:Mbuild}
BUILD_DEPENDS+=	${NINJA_CMD}:${_NINJA_PORT}
# Humanize build log and include percentage of completed jobs %p in it.
# See samu(1) or the Ninja manual.
MAKE_ENV+=	NINJA_STATUS="[%p %s/%t] "
.  endif

.  if ${ninja_ARGS:Mmake}
.    if ${NINJA_DEFAULT} == ninja && !defined(_SAMURAI_FROM_ARGS)
# samu does not support GNU-style args, so we cannot simply append `-v`
# to MAKE_ARGS to enable verbosity. This is instead accomplished via
# the SAMUFLAGS environment variable defined above in MAKE_ENV.
MAKE_ARGS+=	-v
.    endif
CMAKE_ARGS+=	-GNinja
MAKEFILE=
MAKE_CMD=	${NINJA_CMD}
MAKE_FLAGS=
# Set a minimal job of 1
_MAKE_JOBS=	-j${MAKE_JOBS_NUMBER}
_DESTDIR_VIA_ENV=	yes
.  endif

.  if ${ninja_ARGS:Mrun}
RUN_DEPENDS+=	${NINJA_CMD}:${_NINJA_PORT}
.  endif

.endif
