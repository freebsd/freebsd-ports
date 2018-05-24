# $FreeBSD$
#
# Provide support for corosync ports
#
# Feature:		corosync
# Usage:		USES=coroync
#
# MAINTAINER: dpejesh@yahoo.com

.if !defined(_INCLUDE_USES_COROSYNC_MK)
_INCLUDE_USES_COROSYNC_MK=	yes

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
_VALID_COROSYNC_VER=	2 3

.if ! ${_VALID_COROSYNC_VER:M${COROSYNC_DEFAULT}}
IGNORE=	Invalid corosync default version ${COROSYNC_DEFAULT}; valid versions are ${_VALID_COROSYNC_VER}
.endif

.if exists(${LOCALBASE}/sbin/corosync)
_COROSYNC_INSTALLED_VER!=  ${LOCALBASE}/sbin/corosync -v 2>/dev/null
_COROSYNC_INSTALLED_VER:=  ${_COROSYNC_INSTALLED_VER:M'*':C/'//g}
_COROSYNC_INSTALLED_VER_MAJOR=	${_COROSYNC_INSTALLED_VER:C/([0-9]*).[0-9]*.*/\1/g}
_COROSYNC_INSTALLED_VER_MINOR=	${_COROSYNC_INSTALLED_VER:C/[0-9]*.([0-9]*).*/\1/g}

# Currently corosync 3 is tagged 2.99.x so this is a temporary
# work around until the final version is released.
.  if ${_COROSYNC_INSTALLED_VER_MAJOR} == 2 && ${_COROSYNC_INSTALLED_VER_MINOR} == 99
_COROSYNC_INSTALLED_VER_MAJOR=	3
_COROSYNC_INSTALLED_VER_MINOR=	0
.  endif

.  if ${COROSYNC_DEFAULT} != ${_COROSYNC_INSTALLED_VER_MAJOR}
IGNORE=	DEFAULT_VERSIONS=corosync=${COROSYNC_DEFAULT} but ${_COROSYNC_INSTALLED_VER} is installed
.  endif
.endif

BUILD_DEPENDS+=	corosync:net/corosync${COROSYNC_DEFAULT}
RUN_DEPENDS+=	corosync:net/corosync${COROSYNC_DEFAULT}

.endif
