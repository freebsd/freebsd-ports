# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware-guestd
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
CATEGORIES=	emulators
MASTER_SITES=	# bundled with VMware itself
DISTNAME=	vmware-freebsd-tools

MAINTAINER=	matusita@FreeBSD.org
COMMENT=VMware time synchronization daemon for FreeBSD guest OS (for VMware 3.x)

LIB_DEPENDS=	c.3:${PORTSDIR}/misc/compat3x

DISTDIR=	${MOUNT_PT}
IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/vmware-freebsd-tools

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
NO_LATEST_LINK=	yes
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

VMWARE_VER=	3.2.1
BUILD_VER=	2237

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
MOUNT_DEV?=	/dev/acd0c
.else
MOUNT_DEV?=	/dev/acd0
.endif
MOUNT_PT?=	/mnt
MOUNT=		/sbin/mount
UMOUNT=		/sbin/umount

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
	${INSTALL_PROGRAM} ${WRKSRC}/vmware-guestd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/checkvm ${PREFIX}/sbin
	@if [ ! -f ${PREFIX}/etc/rc.d/vmware-guestd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/vmware-guestd.sh startup file."; \
		${INSTALL_SCRIPT} -m 755 ${FILESDIR}/vmware-guestd.sh ${PREFIX}/etc/rc.d; \
	fi
	-${PREFIX}/sbin/vmware-guestd --cmd toolinstall.end

.include <bsd.port.post.mk>
