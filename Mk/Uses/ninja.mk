# Provide support to use Ninja
#
# Feature:		ninja
# Usage:		USES=ninja
# Valid ARGS:		build, make (default), run
#
# build			add a build dependency on ninja
# make			use ninja for the build instead of make, implies "build"
# run			add a run dependency on ninja
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_NINJA_MK)
_INCLUDE_USES_NINJA_MK=	yes

_valid_ARGS=	build make run

.for _arg in ${ninja_ARGS}
.    if empty(_valid_ARGS:M${_arg})
IGNORE=	'USES+= ninja:${ninja_ARGS}' usage: argument [${_arg}] is not recognized
.    endif
.endfor

.if empty(ninja_ARGS)
ninja_ARGS+=	make
.endif

.if ${ninja_ARGS:Mmake}
ninja_ARGS+=	build
.endif

.if ${NINJA_DEFAULT} == ninja
NINJA_CMD=	ninja
_NINJA_PORT=	devel/ninja
.elif ${NINJA_DEFAULT} == samurai
NINJA_CMD=	samu
_NINJA_PORT=	devel/samurai
MAKE_ENV+=	SAMUFLAGS="-v -j${MAKE_JOBS_NUMBER}"
.  if ${ninja_ARGS:Mbuild} && !${BINARY_ALIAS:U:Mninja=*}
# Cmake and Meson have native support for Samurai and detect and
# use it when Ninja is not available in the build environment.  The
# alias is needed for other ports which call Ninja directly and do
# not fall back to Samurai. There should be no harm in providing it
# generally.
BINARY_ALIAS+=	ninja=samu
.  endif
.else
IGNORE=	invalid DEFAULT_VERSIONS+=ninja=${NINJA_DEFAULT}
.endif

.if ${ninja_ARGS:Mbuild}
BUILD_DEPENDS+=	${NINJA_CMD}:${_NINJA_PORT}
# Humanize build log and include percentage of completed jobs %p in it.
# See samu(1) or the Ninja manual.
MAKE_ENV+=	NINJA_STATUS="[%p %s/%t] "
.endif

.if ${ninja_ARGS:Mmake}
.  if ${NINJA_DEFAULT} == ninja
# samu does not support GNU-style args, so we cannot just append
# -v last.  samu gets this via SAMUFLAGS above but ninja does not
# support an equivalent environment variable.
MAKE_ARGS+=	-v
.  endif
CMAKE_ARGS+=	-GNinja
MAKEFILE=
MAKE_CMD=	${NINJA_CMD}
MAKE_FLAGS=
# Set a minimal job of 1
_MAKE_JOBS=	-j${MAKE_JOBS_NUMBER}
_DESTDIR_VIA_ENV=	yes
.endif

.if ${ninja_ARGS:Mrun}
RUN_DEPENDS+=	${NINJA_CMD}:${_NINJA_PORT}
.endif

.endif
