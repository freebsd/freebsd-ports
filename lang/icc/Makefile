# New ports collection makefile for:	icc
# Date created:         24.Jan.2002
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icc
PORTVERSION=	6.0.149
CATEGORIES=	lang linux
MASTER_SITES=
DISTNAME=	l_cc_pu_6.0.149
EXTRACT_SUFX=	.tar

MAINTAINER=	netchild@FreeBSD.org

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio

RESTRICTED=	Intel forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=		i386

USE_LINUX=		yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes

ICC_SITE=	http://www.intel.com/software/products/compilers/

.include <bsd.port.pre.mk>

ICCCFGVAL!=	${UNAME} -r | ${SED} -e 's/\..*//'

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"Please manually download ${DISTFILES} from ${ICC_SITE}, e.g. from ${ICC_SITE}c60l/noncom.htm or from https://premier.intel.com/. Put it into ${DISTDIR} and run make again."
.endif

post-extract:
.for i in \
	intel-icc6-6.0-149.i386.rpm \
#	intel-ildb6-6.0-208.i386.rpm \
#	intel-isubh6-6.0-149.i386.rpm \
#	intel-ecc6-6.0-149.ia64.rpm \
#	intel-eldb6-6.0-208.ia64.rpm \
#	intel-esubh6-6.0-149.ia64.rpm
	@cd ${WRKSRC};  rpm2cpio ${i} | cpio -idu --quiet
.endfor

pre-patch:
# Allow everyone to use it
	@${CHMOD} a+rx ${WRKSRC}/opt
# Remove unneded/unsafe access rights
.for i in docs ia32/include ia32/lib
	@${FIND} ${WRKSRC}/opt/intel/compiler60/${i} -type f -print0 | \
		xargs -0 ${CHMOD} a-x,g-w
.endfor
	@${FIND} ${WRKSRC}/opt -type d -print0 | xargs -0 ${CHMOD} go-w
# Use the Linux ABI for the binaries
.for i in INTEL iccbin iccfilt icid icpcbin icpi lmgrd.intel lmutil mcpcom \
	profmerge proforder xiar xild
	@brandelf -t Linux ${WRKSRC}/opt/intel/compiler60/ia32/bin/${i}
.endfor

post-patch:
# Correct some paths and patch some files
.for i in ia32/bin/icc ia32/bin/icc.cfg ia32/bin/iccvars.csh \
	ia32/bin/iccvars.sh ia32/bin/icpc ia32/bin/icpc.cfg docs/csupport
	@${SED} 's@export -n IA32ROOT; unset IA32ROOT;@@g; s@-a "<INSTALLDIR>/compiler60/ia32/bin/icc" @@g; s@-a "<INSTALLDIR>/compiler60/ia32/bin/icpc" @@g; s@\<INSTALLDIR\>@${PREFIX}/intel@g; s@-tp p6@@; s@man -w@manpath -q@g; s:\<INSTALLTIMECOMBOPACKAGEID\>:Intel(R) C++ Compiler for Linux:g' \
		${WRKSRC}/opt/intel/compiler60/${i} \
		>${WRKSRC}/opt/intel/compiler60/${i}.seded
	@${MV} -f ${WRKSRC}/opt/intel/compiler60/${i}.seded \
		${WRKSRC}/opt/intel/compiler60/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/intel/compiler60/${i}
.endfor
# Remove unneeded files
	@${RM} ${WRKSRC}/opt/intel/compiler60/ia32/include/yvals.h.orig
.if defined(NOPORTDOCS)
	@${RM} -rf ${WRKSRC}/opt/intel/compiler60/docs
.endif
# Provide a more FreeBSD'ish compile environment
	@${ECHO} -e "\n-Ulinux\n-U__linux__\n-U__linux\n\n-D__FreeBSD__=${ICCCFGVAL}\n-D__ELF__=1\n" >>${WRKSRC}/opt/intel/compiler60/ia32/bin/icc.cfg
# \n-Qlocation,ld,/usr/bin\n\n-sox-\n
# Some magic to be able to link
	@${SED} 's:@@PREFIX@@:${PREFIX}:g' ${FILESDIR}/ld >${WRKSRC}/opt/intel/compiler60/ia32/bin/ld
	@${CHMOD} 755 ${WRKSRC}/opt/intel/compiler60/ia32/bin/ld
	@${MKDIR} ${WRKSRC}/opt/intel/compiler60/ia32/bin/real
# Do not use the linux ld if it exists
	@${LN} -s /usr/bin/ld ${WRKSRC}/opt/intel/compiler60/ia32/bin/real

do-install:
	@cd ${WRKSRC}/opt && ${TAR} -cf - . | \
		${TAR} -xf - -C ${PREFIX}

post-install:
	@${ECHO_CMD} "${PKGNAME} is now installed in ${PREFIX}/intel, to use it you have to"
	@${ECHO_CMD} "put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO_CMD} "${PREFIX}/intel/licenses) directory and add"
	@${ECHO_CMD} "${PREFIX}/intel/compiler60/ia32/bin to your PATH."

.include <bsd.port.post.mk>
