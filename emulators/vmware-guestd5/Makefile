# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
PORTREVISION?=	2
CATEGORIES=	emulators kld
MASTER_SITES=	# bundled with VMware Workstation
PKGNAMESUFFIX?=	-guestd
DISTNAME=	vmware-freebsd-tools

MAINTAINER=	ports@FreeBSD.org
COMMENT?=VMware guest OS supporting daemon (VMware Workstation 5.x, FreeBSD version)

.if defined(VMWARE_X_PORTS)
RUN_DEPENDS=	${LOCALBASE}/sbin/vmware-guestd:${PORTSDIR}/emulators/vmware-guestd5
.endif

NO_LATEST_LINK=	yes

DISTDIR=	${MOUNT_PT}
IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/vmware-tools-distrib

ONLY_FOR_ARCHS=	i386 amd64
IS_INTERACTIVE=	yes
.if defined(VMWARE_X_PORTS)
USE_XORG=	x11
NO_BUILD=	yes
.if defined(WITH_VMWARE_GTK)
PLIST_SUB+=	INSTALLXGTKTOOL:=""
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_XORG=	x11 xsxt
USE_GNOME=	glib12 gtk12
LIB_DEPENDS+=	c.6:${PORTSDIR}/misc/compat6x
.else
PLIST_SUB+=	INSTALLXGTKTOOL:="@comment "
.endif
.else
USE_RC_SUBR=	vmware-guestd
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

VMWARE_VER=	5.5.5
BUILD_VER=	56455

.include <bsd.port.pre.mk>

MOUNT_DEV?=	/dev/acd0
MOUNT_PT?=	/mnt
MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

.if ${ARCH} == i386
BITS?=		32-6
.else # ${ARCH} == amd64
BITS?=		64-6
.endif

.if defined(VMWARE_X_PORTS)

PLIST_SUB+=	INSTALLXSERVER4:="@comment "

.else

VMWARE_KMODDIR=	${PREFIX}/lib/vmware-tools/modules

.if !defined(WITHOUT_VMWARE_VMMEMCTL) && exists(/usr/src/sys/Makefile)
WITH_VMWARE_VMMEMCTL=YES
.endif
.if !defined(WITHOUT_VMWARE_VMXNET) && (${ARCH} == i386)
WITH_VMWARE_VMXNET=YES
.endif

.if defined(WITH_VMWARE_VMMEMCTL)
PLIST_SUB+=	VMWARE_VMMEMCTL:=""
.else
PLIST_SUB+=	VMWARE_VMMEMCTL:="@comment "
.endif

.if defined(WITH_VMWARE_VMXNET)
PLIST_SUB+=	VMWARE_VMXNET:=""
.if ${BITS} == 32-6
VMWARE_VMXNET_PATH=	6.0-i386/vmxnet.ko
.else
VMWARE_VMXNET_PATH=	6.0-amd64/vmxnet.ko
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
	${INSTALL_PROGRAM} ${WRKSRC}/lib/bin${BITS}/vmware-toolbox-tcl ${LOCALBASE}/bin
	${LN} -sfh vmware-toolbox-tcl ${LOCALBASE}/bin/vmware-toolbox
.if defined(WITH_VMWARE_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/lib/bin${BITS}/vmware-toolbox-gtk ${LOCALBASE}/bin
.endif
	if [ ! -d ${LOCALBASE}/lib/modules/input ] ; then \
		${MKDIR} ${LOCALBASE}/lib/modules/input ; \
	fi
.if ${ARCH} == i386
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XOrg/6.8.x/vmmouse_drv.o ${LOCALBASE}/lib/modules/input/vmmouse_drv.o_VMware
.else
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/XOrg/6.8.x_64/vmmouse_drv.o ${LOCALBASE}/lib/modules/input/vmmouse_drv.o_VMware
.endif
	-${WRKSRC}/lib/sbin${BITS}/vmware-guestd --cmd toolinstall.end

.else

post-patch:
	LC_CTYPE=C ${REINPLACE_CMD} "`${PRINTF} 's|\0152\013\0350|\0152\\\n\0350|g'`" \
		${WRKSRC}/lib/sbin${BITS}/vmware-checkvm

do-build:
.if defined(WITH_VMWARE_VMMEMCTL)
	(cd ${WRKDIR}/vmmemctl-only; make)
.endif

do-install:
	@if [ -f ${PREFIX}/etc/rc.d/${USE_RC_SUBR} ]; then \
		${ECHO_CMD} "Remove old ${PREFIX}/etc/rc.d/${USE_RC_SUBR} before install."; \
		exit 1; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/lib/sbin${BITS}/vmware-guestd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/lib/sbin${BITS}/vmware-checkvm ${PREFIX}/sbin
.if defined(WITH_VMWARE_VMMEMCTL)
	${MKDIR} ${VMWARE_KMODDIR}
	${INSTALL_KLD} ${WRKDIR}/vmmemctl-only/vmmemctl.ko ${VMWARE_KMODDIR}
.endif
.if defined(WITH_VMWARE_VMXNET)
	${MKDIR} ${VMWARE_KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/lib/modules/binary/FreeBSD${VMWARE_VMXNET_PATH} ${VMWARE_KMODDIR}
.endif
	-${WRKSRC}/lib/sbin${BITS}/vmware-guestd --cmd toolinstall.end
	${MKDIR} ${PREFIX}/share/vmware-tools
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/poweroff-vm-default
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/poweron-vm-default
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/resume-vm-default
	${LN} -sfh /usr/bin/true ${PREFIX}/share/vmware-tools/suspend-vm-default
	${LN} -sfh ${PREFIX}/share/vmware-tools /etc/vmware-tools

.endif

.include <bsd.port.post.mk>
