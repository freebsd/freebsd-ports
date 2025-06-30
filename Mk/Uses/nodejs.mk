# Provide support for Node.js
#
# Feature:	nodejs
#
# Usage:	USES=nodejs[:args]
#   Valid args:
#   - build     use node as build-time dependency
#   - run       use node as runtime dependency
#   - env       set the environment (NODEJS_VERSION and NODEJS_SUFFIX)
#   - version   available version: lts, current, 18, 20, 22, 24
#
# Note:
# - The supported versions follow upstream release schedule
#   https://github.com/nodejs/Release/blob/main/README.md#release-schedule
#   - lts is 22 now
#   - current is 24 now
# - USES=nodejs means USES=nodejs:build,run
# - If you define a version, you must provide run and/or build
#
# MAINTAINER: sunpoet@FreeBSD.org

.if !defined(_INCLUDE_USES_NODEJS_MK)
_INCLUDE_USES_NODEJS_MK=	yes

_VALID_NODEJS_VERSIONS=	18 20 22 24 current lts

.  if ! ${_VALID_NODEJS_VERSIONS:M${NODEJS_DEFAULT}}
IGNORE=	Invalid default nodejs version ${NODEJS_DEFAULT}; valid versions are ${_VALID_NODEJS_VERSIONS}
.  endif

.  if !empty(nodejs_ARGS:Nbuild:Nenv:Nrun:Nlts:Ncurrent:N18:N20:N22:N24)
IGNORE=		USES=nodejs has invalid arguments ${nodejs_ARGS}
.  endif

.  if empty(nodejs_ARGS)
nodejs_ARGS=	build,run
.  endif

.undef _NODEJS_VER
.  for version in ${_VALID_NODEJS_VERSIONS}
.    if ${nodejs_ARGS:M${version}}
_NODEJS_VER=	${version}
.    endif
.  endfor

.  if !defined(_NODEJS_VER)
_NODEJS_VER=	${NODEJS_DEFAULT}
.  endif

NODEJS_VERSION=	${_NODEJS_VER:S|current|24|:S|lts|22|}
NODEJS_SUFFIX=	-node${NODEJS_VERSION}

.  if ${nodejs_ARGS:M*build*}
BUILD_DEPENDS+=	node:www/node${NODEJS_VERSION}
.  endif
.  if ${nodejs_ARGS:M*run*}
RUN_DEPENDS+=	node:www/node${NODEJS_VERSION}
.  endif

.endif
