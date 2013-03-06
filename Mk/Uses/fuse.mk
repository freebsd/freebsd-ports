# $FreeBSD$
#
# handle dependency on the fuse port
#
# MAINTAINER: portmgr@FreeBSD.org
#
.if !defined(_INCLUDE_FUSE_MK)
_INCLUDE_FUSE_MK=	yes

LIB_DEPENDS+=	fuse:${PORTSDIR}/sysutils/fusefs-libs
.if !exists(/sbin/mount_fusefs)
RUN_DEPENDS+=	mount_fusefs:${PORTSDIR}/sysutils/fusefs-kmod
.endif

.endif
