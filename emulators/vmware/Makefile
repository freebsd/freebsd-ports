# ports collection makefile for:    VMware For Linux
# Version required:     1.1.1
# Date created:         Fri 26 Nov 19:16:47 EST 1999
# Whom:                 vns@delta.odessa.ua
#
# $FreeBSD$
# $vmFreeBSD: vmware/vmmon-only/freebsd/port/Makefile,v 1.8 1999/12/17 00:38:27 vsilyaev Exp $
#

VERSION=	1.1.2
BUILD=		364
VMMON_FREEBSD_VERSION = 0.94
VMNET_FREEBSD_VERSION = 0.10
LINUX_DIR=	/compat/linux

CATEGORIES=	emulators
MAINTAINER=	vns@delta.odessa.ua
ONLY_FOR_ARCHS= i386
RUN_DEPENDS=    ${LINUX_DIR}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base
USE_XLIB=	yes
VMWARE_BINMODE=	4555


DISTNAME=       VMware-${VERSION}-${BUILD}
PKGNAME=        vmware-${VERSION}
MASTER_SITES=	http://www4.vmware.com/software/ \
		http://vmware-svca.www.conxion.com/software/ \
		http://vmware-chil.www.conxion.com/software/ \
		http://vmware-heva.www.conxion.com/software/ \
		http://www.vmware.co.uk/software/ \
		http://mirror.aarnet.edu.au/pub/vmware/software/ \
		ftp://mirror.aarnet.edu.au/pub/vmware/software/

WRKSRC=		${WRKDIR}/vmware-distrib 

VMMON_PATCH=	vmmon-freebsd-${VMMON_FREEBSD_VERSION}.tar.gz \
		vmnet-freebsd-${VMNET_FREEBSD_VERSION}.tar.gz
PATCH_SITES=	http://www.mindspring.com/~vsilyaev/vmware/files/ \
		ftp://mirror.aarnet.edu.au/pub/vmware/freebsd/ \
		http://mirror.aarnet.edu.au/pub/vmware/freebsd/
		
PATCHFILES=	${VMMON_PATCH}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400013
BROKEN=	YES
.endif

.if exists(${MASTERDIR}/Makefile.inc.net)
.include "${MASTERDIR}/Makefile.inc.net"
.endif

.if exists(${MASTERDIR}/Makefile.inc.linproc)
.include "${MASTERDIR}/Makefile.inc.linproc"
.endif

VMSUBDIR=lib/vmware
VMDIR=${PREFIX}/${VMSUBDIR}
SCRIPTS_ENV+=LINUX_DIR=${LINUX_DIR} \
		VMNET_HOST_IP=${VMNET_HOST_IP} \
		VMNET_NETMASK=${VMNET_NETMASK}

MAKE_ARGS="KMODDIR=${VMDIR}/lib/modules"

#
# Small hack for alternate processing patchfiles
#
GZCAT=${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/extract 

MAN1= vmware.1

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	
setoptions:
	${SED} -e 's;@@PREFIX@@;${PREFIX};' ${FILESDIR}/vmware > ${WRKDIR}/vmware
	${SED} -e 's;@@PREFIX@@;${PREFIX};' \
	-e 's;@@HOST_IP@@;${VMNET_HOST_IP};' \
	-e 's;@@NETMASK@@;${VMNET_NETMASK};' \
	${FILESDIR}/config > ${WRKDIR}/config

	${SED} -e 's;@@PREFIX@@;${PREFIX};' \
	-e 's;@@NETWORKING@@;${VMNET_NETWORKING};' \
	-e 's;@@HOST_IP@@;${VMNET_HOST_IP};' \
	-e 's;@@NETMASK@@;${VMNET_NETMASK};' \
	${FILESDIR}/vmware.sh> ${WRKDIR}/vmware.sh
	
pre-install: setoptions
	${INSTALL_MAN} ${WRKSRC}/man/man1/vmware.1 ${MANPREFIX}/man/man1
	${MKDIR} ${VMDIR}/lib/modules
	
	${MKDIR} ${PREFIX}/etc/vmware
	${INSTALL_DATA} ${WRKDIR}/config ${PREFIX}/etc/vmware
	
	${INSTALL_SCRIPT} ${WRKDIR}/vmware.sh ${PREFIX}/etc/rc.d

	${MKDIR} ${VMDIR}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/fakeprocfs.sh ${VMDIR}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/df ${VMDIR}/bin 
	[ -f ${LINUX_DIR}/bin/df ] || ${LN} -s ${VMDIR}/bin/df ${LINUX_DIR}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pl ${VMDIR}/bin
	for i in \
		 vmnet-bridge vmnet-dhcpd vmnet-sniffer \
		 vmware-loop vmware-ping vmware-wizard \
		 ; do \
	 ${INSTALL_SCRIPT} ${WRKSRC}/bin/$${i} ${VMDIR}/bin; \
	done
.if defined(USE_LINPROC)
	${INSTALL_SCRIPT} -m ${VMWARE_BINMODE} ${WRKSRC}/bin/vmware ${VMDIR}/bin
	${LN} -s ${VMDIR}/bin/vmware ${PREFIX}/bin/
.else
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vmware ${VMDIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/vmware ${PREFIX}/bin
.endif
	${MKDIR} ${VMDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/config ${VMDIR}/lib
	${MKDIR} ${VMDIR}/lib/help
	${INSTALL_DATA} ${WRKSRC}/lib/help/* ${VMDIR}/lib/help
	${MKDIR} ${VMDIR}/lib/xkeymap
	${INSTALL_DATA} ${WRKSRC}/lib/xkeymap/* ${VMDIR}/lib/xkeymap
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/vmware
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/vmware
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/vmware
.endif
	
post-install:
	${LN} -s ${PREFIX}/etc/vmware /etc/vmware

.include <bsd.port.post.mk>

