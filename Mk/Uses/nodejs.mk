# Provide support for NodeJS
#
# Feature:      nodejs
# Usage:        USES=nodejs or USES=nodejs:args
# Valid ARGS:	build and/or run <version>
# version:      lts, current, 10, 14, 16, 17
# Default is:   build,run
# Note:			if you define a version, you must provide run and/or build
#
# MAINTAINER: bhughes@FreeBSD.org

.if !defined(_INCLUDE_USES_NODEJS_MK)
_INCLUDE_USES_NODEJS_MK=	yes

_VALID_NODEJS_VERSION=	10 14 16 17 lts current
_NODEJS_VERSION_SUFFIX=	${NODEJS_DEFAULT}

.if ! ${_VALID_NODEJS_VERSION:M${_NODEJS_VERSION_SUFFIX}}
IGNORE=	Invalid nodejs default version ${_NODEJS_VERSION_SUFFIX}; valid versions are ${_VALID_NODEJS_VERSION}
.endif

.if empty(nodejs_ARGS)
nodejs_ARGS=	build,run
.endif

. if ${nodejs_ARGS:M10}
_NODEJS_VERSION_SUFFIX=	10
. elif ${nodejs_ARGS:M14}
_NODEJS_VERSION_SUFFIX=	14
. elif ${nodejs_ARGS:M16}
_NODEJS_VERSION_SUFFIX=	16
. elif ${nodejs_ARGS:Mlts}
_NODEJS_VERSION_SUFFIX=	lts
. elif ${nodejs_ARGS:M17}
_NODEJS_VERSION_SUFFIX=	17
. elif ${nodejs_ARGS:Mcurrent}
_NODEJS_VERSION_SUFFIX=	current
. elif defined(NODEJS_DEFAULT)
. endif

# The nodejs 17 version is named www/node
. if ${_NODEJS_VERSION_SUFFIX:Mcurrent}
_NODEJS_VERSION_SUFFIX=
. endif
. if ${_NODEJS_VERSION_SUFFIX:M17}
_NODEJS_VERSION_SUFFIX=
. endif
# The nodejs LTS is version 16
. if ${_NODEJS_VERSION_SUFFIX:Mlts}
_NODEJS_VERSION_SUFFIX=	16
. endif

. if ${nodejs_ARGS:M*run*}
RUN_DEPENDS+=	node:www/node${_NODEJS_VERSION_SUFFIX}
. endif
. if ${nodejs_ARGS:M*build*}
BUILD_DEPENDS+=	node:www/node${_NODEJS_VERSION_SUFFIX}
. endif

.endif
