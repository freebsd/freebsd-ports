# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware-tools
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
PORTREVISION=	2
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
NO_BUILD=	yes
NO_LATEST_LINK=	yes
.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

DEPRECATED=	Depends of misc/compat3x, that is deprecated and set to be removed
EXPIRATION_DATE=	2010-11-08

VMWARE_VER=	3.2.1
BUILD_VER=	2237

MOUNT_DEV?=	/dev/acd0
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
	${INSTALL_PROGRAM} ${WRKSRC}/vmware-toolbox ${PREFIX}/bin
	-${LOCALBASE}/sbin/vmware-guestd --cmd toolinstall.end

.include <bsd.port.mk>
