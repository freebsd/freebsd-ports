# $FreeBSD$
#
# handle dependency on the bison port
#
# Feature:	bison
# Usage:	USES=bison or USES=bison:ARGS
# Valid ARGS:	build (default, implicit), run, both, alias, wrappers
#
# 'alias'	will automatically create a BINARY_ALIAS to use base
#		byacc invoked as bison
# 'wrapper'	will automatically create BINARY_WRAPPER to use base
#		byacc with a wrapper to mimic a bit more bison
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_BISON_MK)
_INCLUDE_USES_BISON_MK=	yes

_BISON_DEPENDS=	bison:devel/bison

.if empty(bison_ARGS)
bison_ARGS=	build
.endif

.if ${bison_ARGS} == "build"
BUILD_DEPENDS+=	${_BISON_DEPENDS}
.elif ${bison_ARGS} == "run"
RUN_DEPENDS+=	${_BISON_DEPENDS}
.elif ${bison_ARGS} == "both"
BUILD_DEPENDS+=	${_BISON_DEPENDS}
RUN_DEPENDS+=	${_BISON_DEPENDS}
.elif ${bison_ARGS} == "alias"
BINARY_ALIAS+=	bison=byacc
.elif ${bison_ARGS} == "wrapper"
BINARY_WRAPPERS+=	bison
.else
IGNORE=	USES=bison - invalid args: [${bison_ARGS}] specified
.endif

.endif
