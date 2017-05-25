# $FreeBSD$
#
# handle dependency on groff
#
# Feature:	groff
# Usage:	USES=groff
# Valid ARGS:	build (default, implicit), run, both

.if !defined(_INCLUDE_USES_GROFF_MK)
_INCLUDE_USES_GROFF_MK=	yes

.  if !exists(/usr/bin/groff)
.    if empty(groff_ARGS)
groff_ARGS=	build
.    endif

_GROFF_DEPENDS=	groff:textproc/groff

.    if ${groff_ARGS} == "build"
BUILD_DEPENDS+=	${_GROFF_DEPENDS}
.    elif ${groff_ARGS} == "run"
RUN_DEPENDS+=	${_GROFF_DEPENDS}
.    elif ${groff_ARGS} == "both"
BUILD_DEPENDS+=	${_GROFF_DEPENDS}
RUN_DEPENDS+=	${_GROFF_DEPENDS}
.    else
IGNORE=	USES=groff - invalid args: [${groff_ARGS}] specified
.    endif
.  endif

.endif
