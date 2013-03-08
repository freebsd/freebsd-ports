# $FreeBSD$
#
# handle dependency on the bison port
#
# MAINTAINER: portmgr@FreeBSD.org
#
.if !defined(_INCLUDE_BISON_MK)
_INCLUDE_BISON_MK=	yes

_BISON_DEPENDS=	bison:${PORTSDIR}/devel/bison

.if !defined(bison_ARGS)
BUILD_DEPENDS+=	${_BISON_DEPENDS}
.else
.if ${bison_ARGS} == "build"
BUILD_DEPENDS+=	${_BUILD_DEPENDS}
.elif ${bison_ARGS} == "run"
RUN_DEPENDS+=	${_BUILD_DEPENDS}
.elif ${bison_ARGS} == "both"
BUILD_DEPENDS+=	${_BISON_DEPENDS}
RUN_DEPENDS+=	${_BUILD_DEPENDS}
.else
IGNORE=	Bad usage of USES= bison
.endif
.endif

.endif
