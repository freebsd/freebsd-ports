# $FreeBSD$
#
# Changes some default behaviour of build systems to allow installing as user.
#
# MAINTAINER:	bapt@FreeBSD.org
#
# Feature:	uidfix
# Usage:	USES=uidfix
# Valid ARGS:	none
#
.if !defined(_INCLUDE_USES_UIDFIX_MK)
.if ${UID} != 0
MAKE_ENV+=	BINOWN=${UID} SHAREOWN=${UID} CONFOWN=${UID}
.endif
.endif
