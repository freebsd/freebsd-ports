# New ports collection makefile for:	icc
# Date created:         24.Jan.2002
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icc
PORTVERSION=	6.0.1.304
PORTREVISION=	1
CATEGORIES=	lang linux devel
MASTER_SITES=
DISTNAME=	l_cc_p_6.0.1.304
EXTRACT_SUFX=	.tar

MAINTAINER=	netchild@FreeBSD.org

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio

RESTRICTED=	Intel forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=		i386

USE_LINUX=		yes
USE_REINPLACE=		yes
NO_WRKSUBDIR=		yes
NO_FILTER_SHLIBS=	yes

MAN1=	icc.1
MANPREFIX=	${PREFIX}/intel/compiler60/

ICC_SITE=	http://www.intel.com/software/products/compilers/

.include <bsd.port.pre.mk>

ICCCFGVAL!=	${UNAME} -r | ${SED} -e 's/\..*//'

OBJCOPY?=	/usr/bin/objcopy

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"Please manually download ${DISTFILES} from ${ICC_SITE}, ${ICC_SITE}c60l/noncom.htm or https://premier.intel.com/ \(whichever has the file, to access premier.intel.com you have to register at http://www.intel.com/software/products/registrationcenter/index.htm\). With a little bit of luck it may also be available from ftp://download.intel.com/software/products/compilers/downloads/. Put it into ${DISTDIR} and run make again"
.endif

post-extract:
.for i in \
	intel-icc6-6.0.1-304.i386.rpm \
#	intel-ildb6-6.0.1-308.i386.rpm \
#	intel-isubh6-6.0.1-304.i386.rpm \
#	intel-ecc6-6.0.1-304.ia64.rpm \
#	intel-eldb6-6.0.1-308.ia64.rpm \
#	intel-esubh6-6.0.1-304.ia64.rpm
.if defined(NOPORTDOCS)
	@cd ${WRKSRC} && rpm2cpio 2>/dev/null ${i} | \
		cpio -idfuE ${FILESDIR}/cpio-exclude --quiet \
		*/opt/intel/compiler60/docs/*
.else
	@cd ${WRKSRC} && rpm2cpio 2>/dev/null ${i} | \
		cpio -idfuE ${FILESDIR}/cpio-exclude --quiet
.endif
.endfor

pre-patch:
# Allow everyone to use it
	@${CHMOD} a+rx ${WRKSRC}/opt
# Remove unneeded/unsafe access rights
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
	@${REINPLACE_CMD} -i "" -e 's:@@PREFIX@@:${PREFIX}:g; s@\<INSTALLDIR\>@${PREFIX}/intel@g; s@man -w@manpath -q@g; s:\<INSTALLTIMECOMBOPACKAGEID\>:${DISTNAME}:g' \
		${WRKSRC}/opt/intel/compiler60/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/intel/compiler60/${i}
.endfor
.for i in cfloat.orig cwchar.orig yvals.h.orig
	@${RM} ${WRKSRC}/opt/intel/compiler60/ia32/include/${i}
.endfor
.for i in icc.orig icpc.orig
	@${RM} ${WRKSRC}/opt/intel/compiler60/ia32/bin/${i}
.endfor
# Remove empty directory
.if defined(NOPORTDOCS)
	@${RM} -rf ${WRKSRC}/opt/intel/compiler60/docs
.endif
# Provide a more FreeBSD'ish compile environment
.for i in icc.cfg icpc.cfg
	@${ECHO} -e "\n-Ulinux\n-U__linux__\n-U__linux\n\n-D__FreeBSD__=${ICCCFGVAL}\n-D__ELF__=1\n" >>${WRKSRC}/opt/intel/compiler60/ia32/bin/${i}
	@${CHMOD} a-x,g-w ${WRKSRC}/opt/intel/compiler60/ia32/bin/${i}
.endfor
# C++ hack for icpc
	@${ECHO} -e "\n-I${PREFIX}/include/stlport\n-Qoption,ld,-CPLUSPLUS\n" >>${WRKSRC}/opt/intel/compiler60/ia32/bin/icpc.cfg
	@cd ${WRKSRC}/opt/intel/compiler60/ia32/bin/ && ${LN} -s icc.cfg iccbin.cfg && ${LN} -s icpc.cfg icpcbin.cfg
# \n-Qlocation,ld,/usr/bin\n\n-sox-\n

do-build:
# Fix unresolved references
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/assert_fail.c \
		${FILESDIR}/cxa_atexit.c ${FILESDIR}/cxa_finalize.c \
		${FILESDIR}/errno_location.c ${FILESDIR}/mcount.S
.if ${OSVERSION} < 500042
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stderr.o ${FILESDIR}/stderr.c
.else
.for i in libcxa.a libimf.a libirc.a libircmt.a libunwind.a
	@${OBJCOPY} --redefine-sym stderr=__stderrp \
		${WRKSRC}/opt/intel/compiler60/ia32/lib/${i}
.endfor
.endif
	@${AR} q ${WRKSRC}/opt/intel/compiler60/ia32/lib/libcxa.a ${WRKSRC}/*.o
# Some magic to be able to link
	@${CC} ${CFLAGS} -o ${WRKSRC}/opt/intel/compiler60/ia32/bin/ld ${FILESDIR}/ld.c
	@${STRIP_CMD} ${WRKSRC}/opt/intel/compiler60/ia32/bin/ld
	@${CHMOD} 755 ${WRKSRC}/opt/intel/compiler60/ia32/bin/ld

do-install:
	@cd ${WRKSRC}/opt && ${TAR} -cf - . | \
		${TAR} -xf - -C ${PREFIX}

post-install:
	@${ECHO_CMD} "${PKGNAME} is now installed in ${PREFIX}/intel, to use it you have to"
	@${ECHO_CMD} "put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO_CMD} "${PREFIX}/intel/licenses) directory and add"
	@${ECHO_CMD} "${PREFIX}/intel/compiler60/ia32/bin to your PATH."
	@${ECHO_CMD}
	@${ECHO_CMD} "In order to be able to compile C++ source with icpc you have to install"
	@${ECHO_CMD} "devel/stlport-icc. (It is a good idea to run 'rehash' before or stlport-icc"
	@${ECHO_CMD} "probably won't find the compiler.)"
	@${ECHO_CMD}
	@${ECHO_CMD} "If you use icc on a Pentium 4 make sure you have 'options CPU_ENABLE_SSE'"
	@${ECHO_CMD} "in your kernel config (have a look at http://www.FreeBSD.org/handbook/"
	@${ECHO_CMD} "if you do not know how to do this), else icc will hang forever."
	@${ECHO_CMD}
	@${ECHO_CMD} "WARNING: If you use icc while having linux-devtools installed, icc will use"
	@${ECHO_CMD} "the wrong includes and therefore will generate bogus binaries!"

.include <bsd.port.post.mk>
