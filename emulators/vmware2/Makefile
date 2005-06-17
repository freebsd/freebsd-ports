# ports collection makefile for:	VMware 2.0 for Linux
# Date created:		Fri 26 Nov 19:16:47 EST 1999
# Whom:			vns@delta.odessa.ua
#
# $FreeBSD$
# $vmFreeBSD: vmware/vmmon-only/freebsd/port/Makefile,v 1.15 2000/07/31 00:54:32 vsilyaev Exp $
#

PORTNAME=	vmware2
PORTVERSION=	2.0.4.1142
PORTREVISION=	2
CATEGORIES=	emulators linux
MASTER_SITES=	${FREEBSD_MODULE_SITES} \
		${VMWARE_MIRROR_SITES}
DISTFILES=	VMware-${PORTVERSION:R}-${PORTVERSION:E}${EXTRACT_SUFX}:vmware \
		vmmon-freebsd-0.98${EXTRACT_SUFX}:patch \
		vmnet-freebsd-0.21${EXTRACT_SUFX}:patch

# Feel free to post your questions/reports/suggestions on this port to
# freebsd-emulation mailing list with the following maintainer address CC'ed.
MAINTAINER=	vsilyaev@mindspring.com
COMMENT=	A virtual machine emulator - a full PC in a window

RUN_DEPENDS=	${LINUXBASE}/dev/rtc:${PORTSDIR}/emulators/rtc

RESTRICTED=	"Not sure if we can redistribute it"

VMWARE_MIRROR_SITES=	\
		http://www.vmware.com/download1/software/:vmware \
		ftp://download1.vmware.com/pub/software/:vmware
#		http://vmware-svca.www.conxion.com/software/:vmware \
#		http://vmware-chil.www.conxion.com/software/:vmware \
#		http://vmware-heva.www.conxion.com/software/:vmware \
#		http://vmware.wespe.de/software/:vmware \
#		ftp://vmware.wespe.de/pub/software:vmware
FREEBSD_MODULE_SITES=	\
		http://www.mindspring.com/~vsilyaev/vmware/files/:patch
#		ftp://mirror.aarnet.edu.au/pub/vmware/freebsd/:patch \
#		http://mirror.aarnet.edu.au/pub/vmware/freebsd/:patch

USE_SUBMAKE=	yes
USE_PERL5=	yes
VMDIR=		${PREFIX}/lib/vmware
SRC_BASE?=	/usr/src

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/vmware-distrib
GZCAT=		${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/extract
MAN1=		vmware.1

MODULES=	vmmon vmnet

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400013
IGNORE=		"Systems prior to 400013 is out of support"
.endif

.if !defined(HAVE_LINPROCFS) && !exists(/modules/linprocfs.ko) && !exists(/boot/kernel/linprocfs.ko) && !exists(${PREFIX}/modules/linprocfs.ko)
IGNORE=		"This software absolutely requires Linux procfs support"
.endif

.if !exists(/${SRC_BASE}/Makefile)
IGNORE=		"Kernel source files required"
.endif

.if exists(${WRKDIRPREFIX}${.CURDIR}/work/Makefile.inc.net)
.include "${WRKDIRPREFIX}${.CURDIR}/work/Makefile.inc.net"
.endif

.if ${OSVERSION} < 500023
VMNET1_MINOR=	0x00010001
.else
VMNET1_MINOR=	0x00800001
.endif

SCRIPTS_ENV+=	LINUXBASE="${LINUXBASE}" \
		VMNET_HOST_IP="${VMNET_HOST_IP}" \
		VMNET_NETMASK="${VMNET_NETMASK}" \
		VMNET1_MINOR="${VMNET1_MINOR}"
MAKE_ARGS=	KMODDIR="${VMDIR}/lib/modules"
PLIST_SUB=	LINUXBASE="${LINUXBASE}" VMNET1_MINOR="${VMNET1_MINOR}"

.if ${OSVERSION} < 500000
PLIST_SUB+=	FREEBSD5="@comment "
.else
PLIST_SUB+=	FREEBSD5=""
.endif

.if ${OSVERSION} >= 500104
LINUXBASE_MAYBE=
.else
LINUXBASE_MAYBE=	${LINUXBASE}
.endif

post-extract:
.for m in ${MODULES}
	${TAR} -xf ${WRKSRC}/lib/modules/source/${m}.tar -C ${WRKSRC}
.endfor
	${GUNZIP_CMD} ${WRKSRC}/man/man1/vmware.1.gz

pre-patch:
	${PERL} -i -ne 'if (m{^Index: vmnet-only/userif\.c$$}..m{^Index: vmnet-only/vm_oui\.h$$}) { next unless m{^Index: vmnet-only/vm_oui\.h$$} } print' ${WRKDIR}/vmnet-freebsd.diff
.for m in ${MODULES}
	${CP} -R ${WRKDIR}/${m}-only ${WRKSRC}/
	${PATCH} ${PATCH_ARGS} < ${WRKDIR}/${m}-freebsd.diff
.endfor

post-patch:
.if ${OSVERSION} >= 500023
	${CAT} ${FILESDIR}/kse.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
.endif
.if ${OSVERSION} >= 500027 || ${OSVERSION} < 500000 && ${OSVERSION} >= 480102
	${CAT} ${FILESDIR}/pmap.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
.endif
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/Makefile.vmmon ${WRKSRC}/vmmon-only/Makefile
	${RM} -rf ${WRKSRC}/vmmon-only/linux/
.if exists(/sys/compat/linux/linux_ioctl.h)
	${PERL} -i -pe 's,i386(/linux/linux_ioctl\.h),compat$$1,' \
		${WRKSRC}/vmnet-only/freebsd/vmnet_linux.c
.endif
.if exists(/usr/include/sys/selinfo.h)
	${PERL} -i -pe 's,<sys/select\.h>,<sys/selinfo.h>,' \
		${WRKSRC}/vmmon-only/freebsd/*.c
.endif
	cd ${WRKSRC}/vmmon-only/freebsd && ${TOUCH} bus_if.h device_if.h
.if ${OSVERSION} >= 500019
	${PERL} -i -pe 's,<machine/ioctl_fd\.h>,<sys/fdcio.h>,' \
		${WRKDIR}/vmmon-only/freebsd/*.c \
		${WRKDIR}/vmware-distrib/vmmon-only/freebsd/*.c
.endif
	${CAT} ${FILESDIR}/kmoddeps.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
	${CAT} ${FILESDIR}/Makefile_FreeBSD.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
.if ${OSVERSION} >= 500038
	${CAT} ${FILESDIR}/fo_ioctl.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
.endif
.if ${OSVERSION} >= 500100
	${CAT} ${FILESDIR}/filedesc.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
	${CAT} ${FILESDIR}/m_waitok.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
.endif
.if ${OSVERSION} >= 500104
	${CAT} ${FILESDIR}/cdevsw.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
	${CAT} ${FILESDIR}/driver_c.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
.endif
.if ${OSVERSION} >= 500109 || ${OSVERSION} < 500000 && ${OSVERSION} >= 480102
	${CAT} ${FILESDIR}/hostif_c.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
.endif
.if ${OSVERSION} >= 500109
	${CAT} ${FILESDIR}/vm_types_h.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1
.endif
	${CAT} ${FILESDIR}/vmnet-only+Makefile.patch | (cd ${WRKSRC} && patch) > /dev/null 2>&1

setoptions:
	${SED} 	-e 's;@@PREFIX@@;${PREFIX};' \
		-e 's;@@HOST_IP@@;${VMNET_HOST_IP};' \
		-e 's;@@NETMASK@@;${VMNET_NETMASK};' \
		${FILESDIR}/config > ${WRKDIR}/config

	${SED} 	-e 's;@@PREFIX@@;${PREFIX};' \
		-e 's;@@LINUXBASE@@;${LINUXBASE_MAYBE};' \
		-e 's;@@NETWORKING@@;${VMNET_NETWORKING};' \
		-e 's;@@BRIDGED@@;${VMNET_BRIDGED};' \
		-e 's;@@BRIDGE_INTF@@;${VMNET_BRIDGED_INTERFACE};' \
		${FILESDIR}/vmware.sh > ${WRKDIR}/vmware.sh

	${SED} 	-e 's;@@PREFIX@@;${PREFIX};' \
		-e 's;@@LINUXBASE@@;${LINUXBASE};' \
		${FILESDIR}/vmware > ${WRKDIR}/vmware

pre-install: setoptions
	${INSTALL_MAN} ${WRKSRC}/man/man1/vmware.1 ${MANPREFIX}/man/man1
	${MKDIR} ${VMDIR}/lib/modules

	${MKDIR} ${PREFIX}/etc/vmware
	${INSTALL_DATA} ${WRKDIR}/config ${PREFIX}/etc/vmware

	${INSTALL_SCRIPT} ${WRKDIR}/vmware.sh ${PREFIX}/etc/rc.d

	${MKDIR} ${VMDIR}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/df ${VMDIR}/bin
	[ -f ${LINUXBASE}/bin/df ] || ${LN} -s ${VMDIR}/bin/df ${LINUXBASE}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pl ${VMDIR}/bin
	for i in \
		 vmnet-bridge vmnet-dhcpd vmnet-sniffer \
		 vmware-loop vmware-ping vmware-wizard \
		 ; do \
		${INSTALL_SCRIPT} ${WRKSRC}/bin/$${i} ${VMDIR}/bin; \
	done
	${INSTALL_SCRIPT} -m 4555 ${WRKSRC}/bin/vmware ${VMDIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/vmware ${PREFIX}/bin
	${MKDIR} ${VMDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/config ${VMDIR}/lib
	${MKDIR} ${VMDIR}/lib/floppies
	${INSTALL_DATA} ${WRKSRC}/lib/floppies/* ${VMDIR}/lib/floppies
	${MKDIR} ${VMDIR}/lib/help
	${INSTALL_DATA} ${WRKSRC}/lib/help/* ${VMDIR}/lib/help
	${MKDIR} ${VMDIR}/lib/xkeymap
	${INSTALL_DATA} ${WRKSRC}/lib/xkeymap/* ${VMDIR}/lib/xkeymap
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/vmware
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/vmware
.for f in README.FreeBSD Hints.FreeBSD
	${INSTALL_DATA} ${FILESDIR}/${f} ${PREFIX}/share/doc/vmware
.endfor
.endif

post-install:
	${LN} -sf ${PREFIX}/etc/vmware /etc/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
