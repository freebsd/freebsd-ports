# New ports collection makefile for:	VMware toolbox for Linux
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware-toolbox
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
CATEGORIES=	emulators linux
MASTER_SITES=	# bundled with VMware Workstation
PKGNAMEPREFIX=	linux-
DISTNAME=	VMwareTools-${VMWARE_VER}-${BUILD_VER}

MAINTAINER=	matusita@FreeBSD.org
COMMENT=VMware toolbox for guest OS (VMware Workstation 5.x, Linux version)

NO_LATEST_LINK=	yes

DISTDIR=	${MOUNT_PT}
IGNOREFILES=	${DISTFILES}
PLIST_FILES=	bin/linux-vmware-toolbox bin/linux-vmware-toolbox-gtk \
		bin/linux-vmware-user
WRKSRC=		${WRKDIR}/vmware-tools-distrib

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_APPS=	gtk xorglibs
NO_BUILD=	yes
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

VMWARE_VER=	5.5.1
BUILD_VER=	19175

.include <bsd.port.pre.mk>

MOUNT_DEV?=	/dev/acd0
MOUNT_PT?=	/mnt
MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

.if ${ARCH} == i386
BITS?=		32
.else # ${ARCH} == amd64
BITS?=		64
.endif

do-fetch:
	@${DO_NADA}
fetch-list:
	@${DO_NADA}

pre-extract:
	@${ECHO} "========================================================================"
	@${ECHO} ""
	@${ECHO} "Before installing this port, please follow this instructions:"
	@${ECHO} ""
	@${ECHO} "     *) Be sure that your VM has an IDE CD-ROM drive."
	@${ECHO} "     *) Select \"VM -> Removable Devices -> CD-ROM -> Edit\" on VMware menu,"
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
.for file in vmware-toolbox-gtk vmware-user
	${BRANDELF} -t Linux ${WRKSRC}/lib/bin${BITS}/${file}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/bin${BITS}/${file} ${PREFIX}/bin/linux-${file}
.endfor
	${LN} -sfh linux-vmware-toolbox-gtk ${PREFIX}/bin/linux-vmware-toolbox

.include <bsd.port.post.mk>
