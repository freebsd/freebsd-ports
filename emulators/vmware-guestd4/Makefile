# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
PORTREVISION=	4
CATEGORIES=	emulators kld
MASTER_SITES=	# bundled with VMware itself
PKGNAMESUFFIX?=	-guestd
DISTNAME=	vmware-freebsd-tools

MAINTAINER=	ports@FreeBSD.org
COMMENT?=VMware time synchronization daemon for FreeBSD guest OS (for VMware 4.x)

.if defined(VMWARE_X_PORTS)
RUN_DEPENDS=	${LOCALBASE}/sbin/vmware-guestd:${PORTSDIR}/emulators/vmware-guestd4
.endif

DISTDIR=	${MOUNT_PT}
IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/vmware-tools-distrib

ONLY_FOR_ARCHS=	i386
USE_RC_SUBR=	vmware-guestd
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif
.if defined(VMWARE_X_PORTS)
USE_XORG=	x11
NO_BUILD=	yes
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}
NO_LATEST_LINK=	yes

VMWARE_VER=	4.5.2
BUILD_VER=	8848

MOUNT_DEV?=	/dev/acd0
MOUNT_PT?=	/mnt
MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

.if !defined(VMWARE_X_PORTS)

.if !defined(WITHOUT_VMWARE_VMMEMCTL)
.if exists(/usr/src/sys/Makefile)
WITH_VMWARE_VMMEMCTL=YES
.endif
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
	@${ECHO} "Choose \"VM\" -> \"Install VMware Tools...\" from the Workstation menu"
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
.if defined(WITH_VMWARE_VMMEMCTL)
	(cd ${WRKDIR}; ${TAR} xf ${WRKSRC}/lib/modules/source/vmmemctl.tar)
.endif

post-patch:
.if defined(WITH_VMWARE_VMMEMCTL)
	LC_CTYPE=C ${REINPLACE_CMD} -e 's|vmmemctl1.o||' ${WRKDIR}/vmmemctl-only/Makefile
	${ECHO_CMD} "OBJS+=vmmemctl1.o" >> ${WRKDIR}/vmmemctl-only/Makefile
.endif
	LC_CTYPE=C ${REINPLACE_CMD} "`${PRINTF} 's|\0152\013\0350|\0152\\\n\0350|g'`" \
		${WRKSRC}/sbin/vmware-checkvm

.if defined(VMWARE_X_PORTS)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vmware-toolbox ${LOCALBASE}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/XF86Config-4 ${LOCALBASE}/etc/XF86Config-4_VMware
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/4.3.x/vmware_drv.o ${LOCALBASE}/lib/modules/drivers/vmware_drv.o_VMware
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/4.2.x/vmmouse_drv.o ${LOCALBASE}/lib/modules/input/vmmouse_drv.o_VMware
	-${LOCALBASE}/sbin/vmware-guestd --cmd toolinstall.end

.else

do-build:
.if defined(WITH_VMWARE_VMMEMCTL)
	(cd ${WRKDIR}/vmmemctl-only; make)
.endif

do-install:
	@if [ -f ${PREFIX}/etc/rc.d/${USE_RC_SUBR} ]; then \
		${ECHO_CMD} "Remove old ${PREFIX}/etc/rc.d/${USE_RC_SUBR} before install."; \
		exit 1; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/sbin/vmware-guestd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sbin/vmware-checkvm ${PREFIX}/sbin
.if defined(WITH_VMWARE_VMMEMCTL)
	${MKDIR} ${VMWARE_KMODDIR}
	${INSTALL_KLD} ${WRKDIR}/vmmemctl-only/vmmemctl.ko ${VMWARE_KMODDIR}
.endif
	-${LOCALBASE}/sbin/vmware-guestd --cmd toolinstall.end
.endif
	${MKDIR} ${PREFIX}/share/vmware-tools
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/poweroff-vm-default
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/poweron-vm-default
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/suspend-vm-default
	${LN} -sfh ${PREFIX}/share/vmware-tools /etc/vmware-tools

.include <bsd.port.mk>
