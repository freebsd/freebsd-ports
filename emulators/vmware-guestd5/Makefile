# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
PORTREVISION?=	2
CATEGORIES=	emulators
MASTER_SITES=	# bundled with VMware Workstation
PKGNAMESUFFIX?=	-guestd
DISTNAME=	vmware-freebsd-tools

MAINTAINER=	matusita@FreeBSD.org
COMMENT?=VMware guest OS supporting daemon (VMware Workstation 5.x, FreeBSD version)

.if defined(VMWARE_X_PORTS)
RUN_DEPENDS=	${LOCALBASE}/sbin/vmware-guestd:${PORTSDIR}/emulators/vmware-guestd5
.endif

DISTDIR=	${MOUNT_PT}
IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/vmware-tools-distrib

ONLY_FOR_ARCHS=	i386 amd64
USE_RC_SUBR=	yes
RC_SCRIPT=	${PREFIX}/etc/rc.d/vmware-guestd.sh
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif
.if defined(VMWARE_X_PORTS)
USE_X_PREFIX=	yes
NO_BUILD=	yes
.if defined(WITH_VMWARE_GTK)
PLIST_SUB+=	INSTALLXGTKTOOL:=""
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GNOME=	glib12 gtk12
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.else
PLIST_SUB+=	INSTALLXGTKTOOL:="@comment "
.endif
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

VMWARE_VER=	5.5.1
BUILD_VER=	19175

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
MOUNT_DEV?=	/dev/acd0c
.else
MOUNT_DEV?=	/dev/acd0
.endif
MOUNT_PT?=	/mnt
MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

.if ${ARCH} == i386
BITS?=		32
.else # ${ARCH} == amd64
BITS?=		64
.endif

.if defined(VMWARE_X_PORTS)

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
.if ${BITS} == 32
PLIST_SUB+=	INSTALLXSERVER3:=""
.else
PLIST_SUB+=	INSTALLXSERVER3:="@comment "
.endif
PLIST_SUB+=	INSTALLXSERVER4:="@comment "
PLIST_SUB+=	INSTALLXVMMOUSE:="@comment "
.elif ${X_WINDOW_SYSTEM:L} == xfree86-4
PLIST_SUB+=	INSTALLXSERVER3:="@comment "
PLIST_SUB+=	INSTALLXSERVER4:=""
PLIST_SUB+=	INSTALLXVMMOUSE:=""
.else
PLIST_SUB+=	INSTALLXSERVER3:="@comment "
PLIST_SUB+=	INSTALLXSERVER4:="@comment "
PLIST_SUB+=	INSTALLXVMMOUSE:=""
.endif

.else

VMWARE_KMODDIR=	${PREFIX}/lib/vmware-tools/modules

.if !defined(WITHOUT_VMWARE_VMMEMCTL) && exists(/usr/src/sys/Makefile)
WITH_VMWARE_VMMEMCTL=YES
.endif
.if !defined(WITHOUT_VMWARE_VMXNET) && (${BITS} == 32)
WITH_VMWARE_VMXNET=YES
.endif

.if defined(WITH_VMWARE_VMMEMCTL)
PLIST_SUB+=	VMWARE_VMMEMCTL:=""
.else
PLIST_SUB+=	VMWARE_VMMEMCTL:="@comment "
.endif

.if defined(WITH_VMWARE_VMXNET)
.if (${OSVERSION} >= 480000) && (${OSVERSION} < 500000) && (${BITS} == 32)
PLIST_SUB+=	VMWARE_VMXNET:=""
VMWARE_VMXNET_PATH=	4.9/vmxnet.ko
.elif (${OSVERSION} >= 500000) && (${OSVERSION} < 600000)
PLIST_SUB+=	VMWARE_VMXNET:=""
.if ${BITS} == 32
VMWARE_VMXNET_PATH=	5.3-i386/vmxnet.ko
.else
VMWARE_VMXNET_PATH=	5.3-amd64/vmxnet.ko
.endif
.else
# VMware doesn't provide vmxnet.ko for other versions
.undef WITH_VMWARE_VMXNET
PLIST_SUB+=	VMWARE_VMXNET:="@comment "
.endif
.else
PLIST_SUB+=	VMWARE_VMXNET:="@comment "
.endif

.if defined(WITH_VMWARE_VMMEMCTL) || defined(WITH_VMWARE_VMXNET)
PLIST_SUB+=	VMWARE_KMODDIR:=""
.else
PLIST_SUB+=	VMWARE_KMODDIR:="@comment "
.endif

.endif

fetch-list:
	@${DO_NADA}

do-fetch:
	@${ECHO} ""
	@${ECHO} "========================================================================"
	@${ECHO} "Choose \"VM\" -> \"Install VMware Tools...\" from VMware Workstation"
	@${ECHO} "menu to connect VM's CD-ROM drive and installation CD image temporary."
	@${ECHO} "Press \"Install\" button when a dialog pops up."
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

.if defined(VMWARE_X_PORTS)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/bin${BITS}/vmware-toolbox-tcl ${X11BASE}/bin
	${LN} -sfh vmware-toolbox-tcl ${X11BASE}/bin/vmware-toolbox
.if defined(WITH_VMWARE_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/lib/bin${BITS}/vmware-toolbox-gtk ${X11BASE}/bin
.endif
.if ${X_WINDOW_SYSTEM:L} != xfree86-3
	if [ ! -d ${X11BASE}/lib/modules/input ] ; then \
		${MKDIR} ${X11BASE}/lib/modules/input ; \
	fi
.endif
.if ${X_WINDOW_SYSTEM:L} == xfree86-3
.if ${BITS} == 32
	${INSTALL_PROGRAM} ${WRKSRC}/lib/configurator/XFree86-3/XF86_VMware_4.5 ${X11BASE}/bin/XF86_VMware
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-3/XF86Config ${X11BASE}/etc/XF86Config_VMware
	@${ECHO} ""
	@${ECHO} "You have installed XFree86 3.x X Server for VMware."
	@${ECHO} "${X11BASE}/etc/XF86Config_VMware is a sample XF86Config file."
	@${ECHO} "Copy this file to /etc/XF86Config before starting X."
.else
	@${ECHO} "There is no XFree86 3.x X server for your system."
	@${ECHO} "Consider upgrading your X to XFree86 4.x or switch to X.Org."
.endif
.elif ${X_WINDOW_SYSTEM:L} == xfree86-4
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/XF86Config-4 ${X11BASE}/etc/XF86Config-4_VMware
	if [ ! -d ${X11BASE}/lib/modules/drivers ] ; then \
		${MKDIR} ${X11BASE}/lib/modules/drivers ; \
	fi
.if ${BITS} == 32
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/4.3.x/vmware_drv.o ${X11BASE}/lib/modules/drivers/vmware_drv.o_VMware
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/4.2.x/vmmouse_drv.o ${X11BASE}/lib/modules/input/vmmouse_drv.o_VMware
.else
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/4.3.x_64/vmware_drv.o ${X11BASE}/lib/modules/drivers/vmware_drv.o_VMware
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XFree86-4/4.3.x_64/vmmouse_drv.o ${X11BASE}/lib/modules/input/vmmouse_drv.o_VMware
.endif
.else
.if ${BITS} == 32
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XOrg/6.8.x/vmmouse_drv.o ${X11BASE}/lib/modules/input/vmmouse_drv.o_VMware
.else
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XOrg/6.8.x_64/vmmouse_drv.o ${X11BASE}/lib/modules/input/vmmouse_drv.o_VMware
.endif
.endif
	-${WRKSRC}/lib/sbin${BITS}/vmware-guestd --cmd toolinstall.end

.else

post-patch:
	${REINPLACE_CMD} "`${PRINTF} 's|\0152\013\0350|\0152\\\n\0350|g'`" \
		${WRKSRC}/lib/sbin${BITS}/vmware-checkvm

do-build:
.if defined(WITH_VMWARE_VMMEMCTL)
	(cd ${WRKDIR}/vmmemctl-only; make)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/sbin${BITS}/vmware-guestd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/lib/sbin${BITS}/vmware-checkvm ${PREFIX}/sbin
.if defined(WITH_VMWARE_VMMEMCTL)
	${MKDIR} ${VMWARE_KMODDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/vmmemctl-only/vmmemctl.ko ${VMWARE_KMODDIR}
.endif
.if defined(WITH_VMWARE_VMXNET)
	${MKDIR} ${VMWARE_KMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/modules/binary/FreeBSD${VMWARE_VMXNET_PATH} ${VMWARE_KMODDIR}
.endif
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/vmware-guestd.sh > ${WRKDIR}/vmware-guestd.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/vmware-guestd.sh ${RC_SCRIPT}
	-${WRKSRC}/lib/sbin${BITS}/vmware-guestd --cmd toolinstall.end
	${MKDIR} ${PREFIX}/share/vmware-tools
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/poweroff-vm-default
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/poweron-vm-default
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/resume-vm-default
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/suspend-vm-default
	${LN} -sfh ${PREFIX}/share/vmware-tools /etc/vmware-tools

.endif

.include <bsd.port.post.mk>
