# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
CATEGORIES=	emulators
MASTER_SITES=	# bundled with VMware itself
PKGNAMESUFFIX?=	-guestd
DISTNAME=	vmware-freebsd-tools

MAINTAINER=	matusita@FreeBSD.org
COMMENT?=VMware time synchronization daemon for FreeBSD guest OS (for VMware 4.x)

.if defined(VMWARE_X_PORTS)
RUN_DEPENDS=	${LOCALBASE}/sbin/vmware-guestd:${PORTSDIR}/emulators/vmware-guestd4
.endif

DISTDIR=	${MOUNT_PT}
IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/vmware-tools-distrib

ONLY_FOR_ARCHS=	i386
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif
.if defined(VMWARE_X_PORTS)
USE_X_PREFIX=	yes
NO_BUILD=	yes
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

VMWARE_VER=	4.0.1
BUILD_VER=	5289

MOUNT_DEV?=	/dev/acd0
MOUNT_PT?=	/mnt
MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

.include <bsd.port.pre.mk>

.if defined(VMWARE_X_PORTS)

.if ${XFREE86_VERSION} == 3
PLIST_SUB+=	INSTALLXSERVER3:=""
PLIST_SUB+=	INSTALLXSERVER4:="@comment "
.else
PLIST_SUB+=	INSTALLXSERVER3:="@comment "
PLIST_SUB+=	INSTALLXSERVER4:=""
.endif

.else

.if !defined(WITHOUT_VMWARE_VMMEMCTL)
WITH_VMWARE_VMMEMCTL=YES
.endif
VMWARE_KMODDIR=	${PREFIX}/lib/vmware-tools/modules
.if defined(WITH_VMWARE_VMMEMCTL)
PLIST_SUB+=	VMWARE_VMMEMCTL:=""
PLIST_SUB+=	VMWARE_KMODDIR:="${VMWARE_KMODDIR}"
.else
PLIST_SUB+=	VMWARE_VMMEMCTL:="@comment "
PLIST_SUB+=	VMWARE_KMODDIR:="@comment "
.endif

.endif

fetch-list:
	@${DO_NADA}

do-fetch:
	@${ECHO} ""
	@${ECHO} "========================================================================"
	@${ECHO} "Choose \"File\" -> \"Install VMware Tools...\" from the Workstation menu"
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
.if !defined(VMWARE_X_PORTS)
	(cd ${WRKDIR}; ${TAR} xf ${WRKSRC}/lib/modules/source/vmmemctl.tar)
.endif

.if defined(VMWARE_X_PORTS)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmware-toolbox ${X11BASE}/bin
.if ${XFREE86_VERSION} == 3
	${INSTALL_PROGRAM} ${WRKSRC}/lib/configurator/XFree86-3/XF86_VMware ${X11BASE}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-3/XF86Config ${X11BASE}/etc/XF86Config_VMware
	@${ECHO} ""
	@${ECHO} "You have installed XFree86 3.x X Server for VMware."
	@${ECHO} "${X11BASE}/etc/XF86Config_VMware is a sample XF86Config file."
	@${ECHO} "Copy this file to /etc/XF86Config before starting X."
.else
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/XF86Config-4 ${X11BASE}/etc/XF86Config-4_VMware
.endif
	-${LOCALBASE}/sbin/vmware-guestd --cmd toolinstall.end

.else

do-build:
.if defined(WITH_VMWARE_VMMEMCTL)
	(cd ${WRKDIR}/vmmemctl-only; make)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbin/vmware-guestd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sbin/vmware-checkvm ${PREFIX}/sbin
	${INSTALL_SCRIPT} -m 755 ${FILESDIR}/vmware-guestd.sh \
				${PREFIX}/etc/rc.d/vmware-guestd.sh.sample
.if defined(WITH_VMWARE_VMMEMCTL)
	${MKDIR} ${VMWARE_KMODDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/vmmemctl-only/vmmemctl.ko ${VMWARE_KMODDIR}
	${INSTALL_SCRIPT} -m 755 ${FILESDIR}/vmware-guest_kmod.sh \
				${PREFIX}/etc/rc.d/vmware-guest_kmod.sh.sample
.endif
	-${LOCALBASE}/sbin/vmware-guestd --cmd toolinstall.end

.endif

.include <bsd.port.post.mk>
