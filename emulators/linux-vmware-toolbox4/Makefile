# New ports collection makefile for:	VMware toolbox for Linux
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware-toolbox
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
CATEGORIES=	emulators linux
MASTER_SITES=	# bundled with VMware itself
PKGNAMEPREFIX=	linux-
DISTNAME=	vmware-linux-tools

MAINTAINER=	matusita@FreeBSD.org
COMMENT=VMware toolbox for guest OS (for VMware 4.x, Linux version)

DISTDIR=	${MOUNT_PT}
IGNOREFILES=	${DISTFILES}
PLIST_FILES=	bin/linux-vmware-toolbox
WRKSRC=		${WRKDIR}/vmware-tools-distrib
STRIP=

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

VMWARE_VER=	4.0.5
BUILD_VER=	6030

MOUNT_DEV?=	/dev/acd0
MOUNT_PT?=	/mnt
MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

do-fetch:
	@${DO_NADA}
fetch-list:
	@${DO_NADA}

pre-extract:
	@${ECHO} "========================================================================"
	@${ECHO} ""
	@${ECHO} "Before installing this port, please follow this instructions:"
	@${ECHO} ""
	@${ECHO} "     *) Be sure that your VM have an IDE CD-ROM."
	@${ECHO} "     *) Select \"Edit -> Removable Devices -> CD-ROM 1 -> Edit\" on VMware menu,"
	@${ECHO} "     *) Check \"Connected\" box."
	@${ECHO} "     *) Check \"Use ISO image\" radio button."
	@${ECHO} "     *) Choose the file \"linux.iso\" for the ISO image.  You will find"
	@${ECHO} "        it under the directory VMware Workstation installed."
	@${ECHO} "     *) Press \"OK\" button."
	@${ECHO} ""
	@${ECHO} "Don't forget to restore the configuration after installing this port."
	@${ECHO} ""
	@${ECHO} "========================================================================"
	@${ECHO} ""
.if !defined(BATCH)
	@${ECHO} -n "Ready to install this ports? [Y/n]: "
	@(read line;			\
	  case "$${line}" in		\
		[Nn]*)			\
			${FALSE} ;;	\
		*)			\
			${TRUE} ;;	\
	  esac)
.endif
	${MKDIR} ${MOUNT_PT}
	-${UMOUNT} ${MOUNT_PT} 2>&1 >/dev/null
	-${UMOUNT} ${MOUNT_DEV} 2>&1 >/dev/null
	${MOUNT} -t cd9660 -r ${MOUNT_DEV} ${MOUNT_PT}

post-extract:
	${UMOUNT} ${MOUNT_DEV}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmware-toolbox ${PREFIX}/bin/linux-vmware-toolbox

.include <bsd.port.mk>
