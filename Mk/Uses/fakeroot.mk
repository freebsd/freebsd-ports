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
BUILD_DEPENDS+=	fakeroot:${PORTSDIR}/security/fakeroot
.if ${UID} != 0
FAKEROOT?=	fakeroot
.endif
.endif
