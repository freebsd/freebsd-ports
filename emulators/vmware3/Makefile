# ports collection makefile for:	VMware 3.2 for Linux
# Date created:		Fri 13 Apr 04:59:47 CET 2003
# Whom:			mbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	vmware3
PORTVERSION=	3.2.1.2242
PORTREVISION=	13
PORTEPOCH=	1
CATEGORIES=	emulators linux kld
MASTER_SITES=	http://download3.vmware.com/software/wkst/:vmware \
		${FREEBSD_MODULE_SITES} \
		${VMWARE_MIRROR_SITES}
DISTFILES=	VMware-workstation-${PORTVERSION:R}-${PORTVERSION:E}${EXTRACT_SUFX}:vmware \
		vmmon-only-${PORTVERSION:R}-20040727${EXTRACT_SUFX}:patch \
		vmnet-only-${PORTVERSION:R}-20040705${EXTRACT_SUFX}:patch

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	A virtual machine emulator - a full PC in a window

RUN_DEPENDS=	/dev/rtc:${PORTSDIR}/emulators/rtc

RESTRICTED=	Not sure if we can redistribute it

VMWARE_MIRROR_SITES=	\
		http://vmware-svca.www.conxion.com/software/:vmware \
		http://vmware-chil.www.conxion.com/software/:vmware \
		http://vmware-heva.www.conxion.com/software/:vmware
FREEBSD_MODULE_SITES=	\
		http://www.break.net/orlando/vmware3/:patch \

USE_SUBMAKE=	yes
VMDIR=		${PREFIX}/lib/vmware
SRC_BASE?=	/usr/src

SUB_FILES=	vmware vmware-wizard pkg-message config 001.vmware.sh
SUB_LIST=	BRIDGED="${VMNET_BRIDGED}" \
		BRIDGE_INTF="${VMNET_BRIDGED_INTERFACE}" \
		HOST_IP="${VMNET_HOST_IP}" \
		NETMASK="${VMNET_NETMASK}" \
		LINUXBASE="${LINUXBASE}" \
		NETWORKING="${VMNET_NETWORKING}" \
		VMNET1_MINOR="${VMNET1_MINOR}"
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
WRKSRC=		${WRKDIR}/vmware-distrib
GZCAT=		${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/extract
MAN1=		vmware.1

MODULES=	vmmon vmnet

.include <bsd.port.pre.mk>

.if !defined(HAVE_LINPROCFS) && !exists(/modules/linprocfs.ko) && !exists(/boot/kernel/linprocfs.ko) && !exists(${PREFIX}/modules/linprocfs.ko) && !exists(/compat/linux/proc/version)
IGNORE=		linprocfs is required, please build the module and/or add it to your kernel
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		kernel source files required
.endif

VMNET1_MINOR=	0x00800001

SCRIPTS_ENV+=	LINUXBASE="${LINUXBASE}" \
		VMNET_HOST_IP="${VMNET_HOST_IP}" \
		VMNET_NETMASK="${VMNET_NETMASK}" \
		VMNET1_MINOR="${VMNET1_MINOR}"
MAKE_ARGS=	KMODDIR="${VMDIR}/modules"
PLIST_SUB=	LINUXBASE="${LINUXBASE}" VMNET1_MINOR="${VMNET1_MINOR}"

post-extract:
.for m in ${MODULES}
	${TAR} -xf ${WRKSRC}/lib/modules/source/${m}.tar -C ${WRKSRC}
.endfor
	${GUNZIP_CMD} ${WRKSRC}/man/man1/vmware.1.gz

pre-patch:
	@${MKDIR} ${WRKSRC}/vmnet-only/freebsd
	@${MKDIR} ${WRKSRC}/vmnet-only/netbsd
	@${MKDIR} ${WRKSRC}/vmmon-only/freebsd
	@${MKDIR} ${WRKSRC}/vmmon-only/netbsd
	@cd ${WRKSRC}/vmmon-only && ${PATCH} -p1 < ${WRKDIR}/vmmon-only.diff
	@cd ${WRKSRC}/vmnet-only && ${PATCH} -p1 < ${WRKDIR}/vmnet-only.diff

.if exists(/sys/compat/linux/linux_ioctl.h)
	${REINPLACE_CMD} -i "" -e 's,i386(/linux/linux_ioctl\.h),compat$$1,' \
		${WRKSRC}/vmnet-only/freebsd/vmnet_linux.c
.endif
.if exists(/usr/include/sys/selinfo.h)
	${REINPLACE_CMD} -i "" -e 's,<sys/select\.h>,<sys/selinfo.h>,' \
		${WRKSRC}/vmmon-only/freebsd/*.c
.endif
	cd ${WRKSRC}/vmmon-only/freebsd && ${TOUCH} bus_if.h device_if.h
	${REINPLACE_CMD} -i "" -e 's,<machine/ioctl_fd\.h>,<sys/fdcio.h>,' \
		${WRKSRC}/vmmon-only/freebsd/*.c

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/Makefile.vmmon ${WRKSRC}/vmmon-only/Makefile
	${CP} ${FILESDIR}/Makefile.vmnet ${WRKSRC}/vmnet-only/Makefile
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/fbsd6-1.patch
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/fbsd6-2.patch
.if ${OSVERSION} > 700000
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/fbsd7-1.patch
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/fbsd7-2.patch
.endif

pre-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/vmware.1 ${MANPREFIX}/man/man1
	${MKDIR} ${VMDIR}/modules

	${MKDIR} ${PREFIX}/etc/vmware
.if exists(${PREFIX}/etc/vmware/config)
		@echo "====> Preserving your previous configuration."
.else
		${INSTALL_DATA} ${WRKDIR}/config ${PREFIX}/etc/vmware
.endif

	${INSTALL_SCRIPT} ${WRKDIR}/001.vmware.sh ${PREFIX}/etc/rc.d

	${MKDIR} ${VMDIR}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/df ${VMDIR}/bin
	[ -f ${LINUXBASE}/bin/df ] || ${LN} -s ${VMDIR}/bin/df ${LINUXBASE}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pl ${VMDIR}/bin

	for i in \
		 vmnet-bridge vmnet-dhcpd vmnet-natd vmnet-netifup \
		 vmnet-sniffer vmware-nmbd vmware-smbd vmware-smbpasswd  \
		 vmware-smbpasswd.bin vmware-ping vmware-wizard \
		 ; do \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/$${i} ${VMDIR}/bin; \
	done
	for f in ${WRKSRC}/lib/bin/*; do \
		${INSTALL_SCRIPT} $${f} ${VMDIR}/bin; \
	done

	${MKDIR} ${VMDIR}/configurator
	for f in ${WRKSRC}/lib/configurator/* ; do \
		${INSTALL_DATA} $${f} ${VMDIR}/configurator; \
	done

	${MKDIR} ${VMDIR}/isoimages
	for f in ${WRKSRC}/lib/isoimages/* ; do \
		${INSTALL_DATA} $${f} ${VMDIR}/isoimages; \
	done

	${MKDIR} ${VMDIR}/licenses/site
	${MKDIR} ${VMDIR}/licenses/user
	${INSTALL_DATA} -m 644 ${WRKSRC}/lib/licenses/user/license.ws.3.0 \
		${VMDIR}/licenses/user
	${INSTALL_SCRIPT} -m 4555 ${WRKSRC}/bin/vmware ${VMDIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/vmware ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/vmware-wizard ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/config ${VMDIR}
	${MKDIR} ${VMDIR}/help
	${INSTALL_DATA} ${WRKSRC}/lib/help/* ${VMDIR}/help

	${MKDIR} ${VMDIR}/xkeymap
	${INSTALL_DATA} ${WRKSRC}/lib/xkeymap/* ${VMDIR}/xkeymap

	${MKDIR} ${VMDIR}/smb/codepages
	${INSTALL_DATA} ${WRKSRC}/lib/smb/codepages/* ${VMDIR}/smb/codepages

	${MKDIR} ${VMDIR}/messages/chef
	${INSTALL_DATA} ${WRKSRC}/lib/messages/chef/* ${VMDIR}/messages/chef
	${MKDIR} ${VMDIR}/messages/ja
	${INSTALL_DATA} ${WRKSRC}/lib/messages/ja/* ${VMDIR}/messages/ja
	${MKDIR} ${VMDIR}/messages/jive
	${INSTALL_DATA} ${WRKSRC}/lib/messages/jive/* ${VMDIR}/messages/jive
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.for f in README.FreeBSD Hints.FreeBSD MultipleInstances.FreeBSD ChangeLog.FreeBSD
	${INSTALL_DATA} ${FILESDIR}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	${LN} -sf ${PREFIX}/etc/vmware ${LINUXBASE}/etc/
	@if [ ! -e ${LINUXBASE}/usr/lib/vmware/bin/vmware ]; then \
		${LN} -sf ${PREFIX}/lib/vmware ${LINUXBASE}/usr/lib/vmware; \
	fi
	@${CAT} ${PKGMESSAGE}

pre-clean:
.if exists(${WRKSRC})
	@${FIND} ${WRKSRC} | ${GREP} \@ | ${XARGS} ${RM}
.endif

.include <bsd.port.post.mk>

.if exists(${WRKDIR}/Makefile.inc.net)
.include "${WRKDIR}/Makefile.inc.net"
.endif
