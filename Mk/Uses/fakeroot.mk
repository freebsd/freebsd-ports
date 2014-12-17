# $FreeBSD$
#
# Changes some default behaviour of build systems to allow installing as user.
#
# Feature:	fakeroot
# Usage:	USES=fakeroot
# Valid ARGS:	none
#
# MAINTAINER:	bapt@FreeBSD.org

.if !defined(_INCLUDE_USES_FAKEROOT_MK)
_INCLUDE_USES_FAKEROOT_MK=	yes
.if ${UID} != 0
BUILD_DEPENDS+=	fakeroot:${PORTSDIR}/security/fakeroot
FAKEROOT?=	fakeroot
.endif
.endif
