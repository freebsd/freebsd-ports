# New ports collection makefile for:	icc
# Date created:         24.Jan.2002
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icc
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	lang linux
MASTER_SITES=	http://www.intel.com/software/products/compilers/c50/linux/
DISTNAME=	cc010911rh71
EXTRACT_SUFX=	.tar

MAINTAINER=	netchild@FreeBSD.org

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	${LINUXBASE}/lib/libc-2.2.2.so:${PORTSDIR}/emulators/linux_base-7

RESTRICTED=	Intel forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=		i386

#USE_LINUX=		yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes

.include <bsd.port.pre.mk>

ICCCFGVAL!=	${UNAME} -r | ${SED} -e 's/\..*//'

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"Please manually download the version for RedHat 7.1 from ${MASTER_SITES} (e.g. http://www.intel.com/software/products/compilers/c50/linux/noncom.htm), put it into ${DISTDIR} and run make again. WARNING: this will lead to a mixed up installation if you already use the default linux emulation. This port uses the linux_base-7 port instead of the default linux_base port"
.endif

post-extract:
.for i in \
	intel-icc-5.0.1-129.i386.rpm \
#	intel-ecc64-5.0.1-71.ia64.rpm \
#	intel-ldb-5.0.1-119.i386.rpm \
#	intel-subh-5.0.1-118.i386.rpm \
#	intel-xenv64-5.0.1-35.ia64.rpm
	@cd ${WRKSRC}; rpm2cpio ${i} | cpio -idu --quiet
.endfor

pre-patch:
	@${CHMOD} a+rx ${WRKSRC}/opt
.for i in docs ia32/include ia32/lib
	@${FIND} ${WRKSRC}/opt/intel/compiler50/${i} -type f -print0 | \
		xargs -0 ${CHMOD} a-x,g-w
.endfor
	@${FIND} ${WRKSRC}/opt -type d -print0 | xargs -0 ${CHMOD} go-w
.for i in icc iccfilt icid icpc icpi mcpcom profmerge proforder
	@brandelf -t Linux ${WRKSRC}/opt/intel/compiler50/ia32/bin/${i}
.endfor
.for i in intelpto lmgrd lmutil
	@brandelf -t Linux ${WRKSRC}/opt/intel/compiler50/flexlm/${i}
.endfor

post-patch:
.for i in ia32/bin/iccvars.csh ia32/bin/iccvars.sh ia32/bin/icc.cfg \
	ia32/bin/icpc.cfg docs/iccsupport
	@${SED} 's@\<INSTALLDIR\>@${PREFIX}/intel@g; s@-tp p6@@' \
		${WRKSRC}/opt/intel/compiler50/${i} \
		>${WRKSRC}/opt/intel/compiler50/${i}.seded
	@${MV} -f ${WRKSRC}/opt/intel/compiler50/${i}.seded \
		${WRKSRC}/opt/intel/compiler50/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/intel/compiler50/${i}
.endfor
	@${RM} ${WRKSRC}/opt/intel/compiler50/ia32/include/yvals.h.orig
.if defined(NOPORTDOCS)
	@${RM} -rf ${WRKSRC}/opt/intel/compiler50/docs
.endif
	@${ECHO} -e "\n-Ulinux\n-U__linux__\n-U__linux\n\n-D__FreeBSD__=${ICCCFGVAL}\n-D__ELF__=1\n" >>${WRKSRC}/opt/intel/compiler50/ia32/bin/icc.cfg

do-install:
	@cd ${WRKSRC}/opt && ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}

post-install:
	@${ECHO_CMD} "${PKGNAME} is now installed in ${PREFIX}/intel, to use it you have to"
	@${ECHO_CMD} "source the appropriate ${PREFIX}/intel/compiler50/ia32/bin/iccvars.{,c}sh"
	@${ECHO_CMD} "script and put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO_CMD} "${PREFIX}/intel/licenses) directory."

.include <bsd.port.post.mk>
