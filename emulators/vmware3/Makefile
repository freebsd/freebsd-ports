# ports collection makefile for:	VMware 2.0 for Linux
# Date created:		Fri 26 Nov 19:16:47 EST 1999
# Whom:			vns@delta.odessa.ua
#
# $FreeBSD$
# $vmFreeBSD: vmware/vmmon-only/freebsd/port/Makefile,v 1.15 2000/07/31 00:54:32 vsilyaev Exp $
#

PORTNAME=	vmware2
PORTVERSION=	2.0.3.799
PORTREVISION=	1
CATEGORIES=	emulators linux
MASTER_SITES=	http://www4.vmware.com/software/ \
		${FREEBSD_MODULE_SITES} \
		${VMWARE_MIRROR_SITES}
DISTFILES=	VMware-${PORTVERSION:R}-${PORTVERSION:E}${EXTRACT_SUFX} \
		vmmon-freebsd-0.98${EXTRACT_SUFX} \
		vmnet-freebsd-0.21${EXTRACT_SUFX}

# Feel free to post your questions/reports/suggestions on this port to
# freebsd-emulation mailing list with the following maintainer address CC'ed.
MAINTAINER=	vns@delta.odessa.ua

RUN_DEPENDS=	${LINUXBASE}/dev/rtc:${PORTSDIR}/emulators/rtc

RESTRICTED=	"Not sure if we can redistribute it"

VMWARE_MIRROR_SITES=	\
		http://vmware-svca.www.conxion.com/software/ \
		http://vmware-chil.www.conxion.com/software/ \
		http://vmware-heva.www.conxion.com/software/ \
		http://www.vmware.co.uk/software/ \
		http://mirror.aarnet.edu.au/pub/vmware/software/ \
		ftp://mirror.aarnet.edu.au/pub/vmware/software/
FREEBSD_MODULE_SITES=	\
		http://www.mindspring.com/~vsilyaev/vmware/files/ \
		ftp://mirror.aarnet.edu.au/pub/vmware/freebsd/ \
		http://mirror.aarnet.edu.au/pub/vmware/freebsd/

USE_LINUX=	yes
VMDIR=		${PREFIX}/lib/vmware

ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/vmware-distrib
GZCAT=		${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/extract
MAN1=		vmware.1

MODULES=	vmmon vmnet

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400013
BROKEN=		"Systems prior to 400013 is out of support"
.endif

.if !defined(HAVE_LINPROCFS) && !exists(/modules/linprocfs.ko) && !exists(/boot/kernel/linprocfs.ko) && !exists(${PREFIX}/modules/linprocfs.ko)
BROKEN=		"This software absolutely requires Linux procfs support"
.endif

.if !exists(/sys/Makefile)
BROKEN=		"Kernel source files required"
.endif

.if exists(${WRKDIRPREFIX}${.CURDIR}/work/Makefile.inc.net)
.include "${WRKDIRPREFIX}${.CURDIR}/work/Makefile.inc.net"
.endif

SCRIPTS_ENV+=	LINUXBASE="${LINUXBASE}" \
		VMNET_HOST_IP="${VMNET_HOST_IP}" \
		VMNET_NETMASK="${VMNET_NETMASK}"
MAKE_ARGS=	KMODDIR="${VMDIR}/lib/modules"
PLIST_SUB=	LINUXBASE="${LINUXBASE}"

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

setoptions:
	${SED} 	-e 's;@@PREFIX@@;${PREFIX};' \
		-e 's;@@HOST_IP@@;${VMNET_HOST_IP};' \
		-e 's;@@NETMASK@@;${VMNET_NETMASK};' \
		${FILESDIR}/config > ${WRKDIR}/config

	${SED} 	-e 's;@@PREFIX@@;${PREFIX};' \
		-e 's;@@LINUXBASE@@;${LINUXBASE};' \
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
