# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware-tools
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
CATEGORIES=	emulators
MASTER_SITES=	# bundled with VMware itself
DISTNAME=	vmware-freebsd-tools

MAINTAINER=	matusita@FreeBSD.org
COMMENT=VMware tools for guest OS (for VMware 3.x, FreeBSD version)

LIB_DEPENDS=	c.3:${PORTSDIR}/misc/compat3x
RUN_DEPENDS=	${LOCALBASE}/sbin/vmware-guestd:${PORTSDIR}/emulators/vmware-guestd3

DISTDIR=	${MOUNT_PT}
IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/vmware-freebsd-tools

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_LATEST_LINK=	yes
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

VMWARE_VER=	3.1.1
BUILD_VER=	1790

MOUNT_DEV?=	/dev/acd0c
MOUNT_PT?=	/mnt
MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
PLIST_SUB+=	INSTALLXSERVER:=""
.else
PLIST_SUB+=	INSTALLXSERVER:="@comment "
.endif

do-fetch:
	@${DO_NADA}
fetch-list:
	@${DO_NADA}

pre-extract:
	@${ECHO} ""
	@${ECHO} "========================================================================"
	@${ECHO} "Choose \"Settings\" -> \"VMware Tools Install...\" from the Wrokstation menu"
	@${ECHO} "to connect the VM's CD-ROM drive temporarily to installation CD image."
	@${ECHO} "========================================================================"
	@${ECHO} ""
.if !defined(BATCH)
	@${ECHO} "This port mounts ${MOUNT_DEV} to ${MOUNT_PT}."
	@${ECHO} ""
	@${ECHO} -n "Are you ready? [Y/n]: "
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
	${MOUNT} -t cd9660 ${MOUNT_DEV} ${MOUNT_PT}

post-extract:
	${UMOUNT} ${MOUNT_PT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vmware-toolbox ${PREFIX}/bin
.if ${XFREE86_VERSION} == 3
	${INSTALL_PROGRAM} ${WRKSRC}/XF86_VMware ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XF86Config.dist ${PREFIX}/etc/XF86Config_VMware
	@${ECHO} ""
	@${ECHO} "You have installed XFree86 3.x X Server for VMware."
	@${ECHO} "${PREFIX}/etc/XF86Config_VMware is a sample XF86Config file."
	@${ECHO} "Copy this file to /etc/XF86Config before starting X."
.endif
	-${LOCALBASE}/sbin/vmware-guestd --cmd toolinstall.end

.include <bsd.port.post.mk>
