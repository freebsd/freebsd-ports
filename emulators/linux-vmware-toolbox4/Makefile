# New ports collection makefile for:	VMware toolbox for Linux
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware-toolbox
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
CATEGORIES=	emulators linux
MASTER_SITES=	# none
PKGNAMEPREFIX=	linux-
DISTNAME=	vmware-linux-tools

MAINTAINER=	matusita@jp.FreeBSD.org

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

RESTRICTED=	"Not sure if we can redistribute this."

.include <bsd.port.pre.mk>

LINUX_FLP?=	${DISTDIR}/linux.flp
MOUNT_PT?=	${WRKDIR}/mnt
.if exists(${LINUX_FLP})
MOUNT_DEV?=	vn0
.else
MOUNT_DEV?=	fd0
.endif
VMWARE_VER=	2.0.3
BUILD_VER=	799

MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount
VNCONFIG=	/usr/sbin/vnconfig

pre-fetch:
	@${ECHO} "========================================================================"
	@${ECHO} ""
	@${ECHO} "To install this port, please do one of these:"
	@${ECHO} ""
	@${ECHO} "  1. Select the menu item \"Devices -> floppy0 -> Edit\" on VMware,"
	@${ECHO} "     and choose the file \"linux.flp\"."
	@${ECHO} ""
	@${ECHO} "  2. Manually put the file \"linux.flp\" in ${DISTDIR}."
	@${ECHO} ""
	@${ECHO} "========================================================================"

do-fetch:
.if exists("${DISTDIR}/${DISTFILES}")
	@${ECHO} "Found ${DISTDIR}/${DISTFILES}."
.else
	${MKDIR} ${MOUNT_PT}
	-@${UMOUNT} ${MOUNT_PT} 2>&1 >/dev/null
	-@${UMOUNT} /dev/${MOUNT_DEV} 2>&1 >/dev/null
.if exists(${LINUX_FLP})
	-@${VNCONFIG} -u /dev/r${MOUNT_DEV} 2>&1 >/dev/null
	${VNCONFIG} -c /dev/r${MOUNT_DEV} ${LINUX_FLP}
.endif
	${MOUNT} -t msdos -r /dev/${MOUNT_DEV} ${MOUNT_PT}
	${CP} ${MOUNT_PT}/${DISTFILES} ${DISTDIR}
	${UMOUNT} /dev/${MOUNT_DEV}
.if exists(${LINUX_FLP})
	${VNCONFIG} -u /dev/r${MOUNT_DEV}
.endif
.endif

do-install:
	${CP} ${WRKSRC}/vmware-toolbox ${PREFIX}/bin/linux-vmware-toolbox

.include <bsd.port.post.mk>
