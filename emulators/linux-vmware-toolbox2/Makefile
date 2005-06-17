# New ports collection makefile for:	VMware toolbox for Linux
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware-toolbox
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
PORTREVISION=	1
CATEGORIES=	emulators linux
MASTER_SITES=	# bundled with VMware itself
PKGNAMEPREFIX=	linux-
DISTNAME=	vmware-linux-tools

MAINTAINER=	matusita@FreeBSD.org
COMMENT=VMware toolbox for guest OS (for VMware 2.x, Linux version)

ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/linux-vmware-toolbox
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}
NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

LINUX_FLP?=	${DISTDIR}/linux.flp
MOUNT_PT?=	${WRKDIR}/mnt
.if exists(${LINUX_FLP})
.if ${OSVERSION} >= 500018
DEV_ATTACH=	/usr/sbin/mdconfig -a -t vnode -f ${LINUX_FLP} -u ${MOUNT_DEV}
DEV_DETACH=	/usr/sbin/mdconfig -d -u ${MOUNT_DEV}
MOUNT_DEV?=	md0
.else
DEV_ATTACH=	/usr/sbin/vnconfig -c ${MOUNT_DEV} ${LINUX_FLP}
DEV_DETACH=	/usr/sbin/vnconfig -u ${MOUNT_DEV}
MOUNT_DEV?=	vn0
.endif
.else
MOUNT_DEV?=	fd0
.endif

VMWARE_VER=	2.0.4
BUILD_VER=	1142

MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

pre-fetch:
.if !exists("${DISTDIR}/${DISTFILES}")
	@${ECHO} "========================================================================"
	@${ECHO} ""
	@${ECHO} "To install this port, please:"
	@${ECHO} ""
	@${ECHO} "     Select the menu item \"Devices -> floppy0 -> Edit\" on VMware,"
	@${ECHO} "     and choose the file \"linux.flp\"."
	@${ECHO} ""
	@${ECHO} "========================================================================"
	@${ECHO} ""
	@${ECHO} -n "Are ready to install this ports? [Y/n]: "
.if !defined(BATCH)
	@(read line;			\
	  case "$${line}" in		\
		[Nn]*)			\
			${FALSE} ;;	\
		*)			\
			${TRUE} ;;	\
	  esac)
.endif
.endif

do-fetch:
.if exists("${DISTDIR}/${DISTFILES}")
	@${ECHO} "Found ${DISTDIR}/${DISTFILES}."
.else
	${MKDIR} ${MOUNT_PT}
	-${UMOUNT} ${MOUNT_PT} 2>&1 >/dev/null
	-${UMOUNT} /dev/${MOUNT_DEV} 2>&1 >/dev/null
.if exists(${LINUX_FLP})
	-${DEV_DETACH} 2>&1 >/dev/null
	${DEV_ATTACH}
.endif
	${MOUNT} -t msdos -r /dev/${MOUNT_DEV} ${MOUNT_PT}
	${CP} ${MOUNT_PT}/${DISTFILES} ${DISTDIR}
	${UMOUNT} /dev/${MOUNT_DEV}
.if exists(${LINUX_FLP})
	${DEV_DETACH}
.endif
.endif

do-install:
	${BRANDELF} -t Linux ${WRKSRC}/vmware-toolbox
	${INSTALL_PROGRAM} ${WRKSRC}/vmware-toolbox ${PREFIX}/bin/linux-vmware-toolbox

.include <bsd.port.post.mk>
