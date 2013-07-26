# $FreeBSD$
#
# handle dependency on the gettext (libintl) port
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	gettext
# Usage:	USES=gettext or USES=gettext:ARGS
# Valid ARGS:	build, run, lib (default, implicit)
#
#
.if !defined(_INCLUDE_USES_GETTEXT_MK)
_INCLUDE_USES_GETTEXT_MK=	yes

_GETTEXT_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

.if !defined(gettext_ARGS)
gettext_ARGS=	lib
.endif

.if ${gettext_ARGS} == "build"
BUILD_DEPENDS+=	${_GETTEXT_DEPENDS}
.elif ${gettext_ARGS} == "run"
RUN_DEPENDS+=	${_GETTEXT_DEPENDS}
.elif ${gettext_ARGS} == "lib"
LIB_DEPENDS+=	intl:${PORTSDIR}/devel/gettext
.else
IGNORE=	USES=gettext - invalid args: [${gettext_ARGS}] specifed
.endif

.endif
