# ports collection makefile for:    VMware For Linux
# Version required:     1.1.1
# Date created:         Fri 26 Nov 19:16:47 EST 1999
# Whom:                 vns@delta.odessa.ua
#
# $vmFreeBSD: vmware/vmmon-only/freebsd/port/Makefile,v 1.8 1999/12/17 00:38:27 vsilyaev Exp $
# $FreeBSD$
#

DISTNAME=       VMware-1.1.2-364
PKGNAME=        vmware-1.1.2
CATEGORIES=	emulators linux
MASTER_SITES=	http://www4.vmware.com/software/ \
		http://vmware-svca.www.conxion.com/software/ \
		http://vmware-chil.www.conxion.com/software/ \
		http://vmware-heva.www.conxion.com/software/ \
		http://www.vmware.co.uk/software/ \
		http://mirror.aarnet.edu.au/pub/vmware/software/ \
		ftp://mirror.aarnet.edu.au/pub/vmware/software/

PATCH_SITES=	http://www.mindspring.com/~vsilyaev/vmware/files/ \
		ftp://mirror.aarnet.edu.au/pub/vmware/freebsd/ \
		http://mirror.aarnet.edu.au/pub/vmware/freebsd/
PATCHFILES=	vmmon-freebsd-0.94.tar.gz \
		vmnet-freebsd-0.10.tar.gz

MAINTAINER=	vns@delta.odessa.ua

RUN_DEPENDS=    ${LINUX_DIR}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

IS_INTERACTIVE=	yes	# vmnet-freebsd-* querries user for network settings

ONLY_FOR_ARCHS= i386
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/vmware-distrib
LINUX_DIR=	/compat/linux
MAN1=		vmware.1

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

VMSUBDIR=	lib/vmware
VMDIR=		${PREFIX}/${VMSUBDIR}
SCRIPTS_ENV+=	LINUX_DIR=${LINUX_DIR} \
		VMNET_HOST_IP=${VMNET_HOST_IP} \
		VMNET_NETMASK=${VMNET_NETMASK}

MAKE_ARGS=	"KMODDIR=${VMDIR}/lib/modules"

# Small hack for alternate processing patchfiles
GZCAT=		${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/extract

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

setoptions:
	${SED} -e 's;@@PREFIX@@;${PREFIX};' ${FILESDIR}/vmware > ${WRKDIR}/vmware
	${SED}  -e 's;@@PREFIX@@;${PREFIX};' \
		-e 's;@@HOST_IP@@;${VMNET_HOST_IP};' \
		-e 's;@@NETMASK@@;${VMNET_NETMASK};' \
	${FILESDIR}/config > ${WRKDIR}/config

	${SED}  -e 's;@@PREFIX@@;${PREFIX};' \
		-e 's;@@NETWORKING@@;${VMNET_NETWORKING};' \
		-e 's;@@HOST_IP@@;${VMNET_HOST_IP};' \
		-e 's;@@NETMASK@@;${VMNET_NETMASK};' \
		${FILESDIR}/vmware.sh > ${WRKDIR}/vmware.sh

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
	${INSTALL_SCRIPT} -m 4555 ${WRKSRC}/bin/vmware ${VMDIR}/bin
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
	@${LN} -s ${PREFIX}/etc/vmware /etc/vmware
.if !defined(BATCH)
	@${ECHO} "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" 
	@${ECHO} "Before launch vmware, execute the next command"
	@${ECHO} ${PREFIX}/etc/rc.d/vmware.sh start
	@${ECHO} 
	@${ECHO} "to load required kernel modules"
	@${ECHO} "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" 
.endif

pre-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc.linproc \
		  ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc.net

.include <bsd.port.post.mk>
