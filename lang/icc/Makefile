# New ports collection makefile for:	icc
# Date created:         24.Jan.2002
# Whom:                 netchild@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icc
PORTVERSION=	8.0.066p070.1
CATEGORIES=	lang linux devel
MASTER_SITES=
DISTNAME=	l_cc_pc_${PORTVERSION:C/p.+$//}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Intels C/C++ compiler, set up to produce native FreeBSD binaries

PATCHLEVEL=	${PORTVERSION:C/(.+p)(.+)$/pe\2/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if ${PORTVERSION} != ${PATCHLEVEL}
DISTFILES+=	${DISTNAME}_${PATCHLEVEL}${EXTRACT_SUFX}
.endif

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
PATCH_DEPENDS=		${LINUXBASE}/etc/redhat-release:${PORTSDIR}/emulators/linux_base

RESTRICTED=	Intel forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=		i386
CONFLICTS=		linux_devtools*

USE_LINUX=		yes
USE_REINPLACE=		yes
NO_FILTER_SHLIBS=	yes

COMPILERDIR=	intel_cc_80
PLIST_SUB=	COMPILERDIR=${COMPILERDIR}
PATCH_WRKSRC=	${WRKSRC}/opt/${COMPILERDIR}

MAN1=		icc.1
MLINKS=		icc.1 icpc.1
MANPREFIX=	${PREFIX}/${COMPILERDIR}/

ICC_SITE=	http://www.intel.com/software/products/compilers/

.include <bsd.port.pre.mk>

EXTRACT_AFTER_ARGS=	| tar -xf - \
			--exclude intel-iidb\*.rpm \
			--exclude intel-isubh\*.rpm \
			--exclude \*ia64.rpm \
			--exclude flexlm64

ICCCFGVAL!=	${UNAME} -r | ${SED} -e 's/\..*//'

.if ( ${OSVERSION} < 502108 )
PLIST_SUB+=	STDARG_H="" SYS_CDEFS_H=""
.else
PLIST_SUB+=	STDARG_H="@comment " SYS_CDEFS_H="@comment "
.endif

.for file in ${DISTFILES}
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${file})
IGNORE=	"Go to Intel Premier Support, https://premier.intel.com, to obtain ${DISTFILES}. Product updates such as this compiler are posted regularly on Premier Support. You must have a license to obtain access to Premier Support. If you do not already have a license go to ${ICC_SITE} to review licensing options \(evaluation, commercial, and free non-commercial\) and obtain a license. Put ${DISTFILES} into ${DISTDIR} and run make again"
.endif
.endfor

.if exists(${LINUXBASE}/boot/kernel.h)
BROKEN=	Cannot coexist with linux_devtools
.endif

post-extract:
	@cd ${WRKSRC} && rpm2cpio.pl 2>/dev/null *.rpm | ${CPIO} -idu --quiet

intel-patch: extract
# Apply patches from Intel.
.if ${PORTVERSION} != ${PATCHLEVEL}
	@${BRANDELF} -t Linux ${WRKSRC}_${PATCHLEVEL}/papply
	@${WRKSRC}_${PATCHLEVEL}/papply ${WRKSRC}_${PATCHLEVEL}/icc.rtp \
		${WRKSRC}/opt/${COMPILERDIR}
.endif

pre-patch: intel-patch
# Remove files we do not neet on FreeBSD.
	@for i in `${CAT} ${FILESDIR}/exclude`; do \
		${RM} -rf ${WRKSRC}/opt/${COMPILERDIR}/$$i; \
	done
.if defined(NOPORTDOCS)
# Remove docs.
	@for i in `${CAT} ${FILESDIR}/exclude_noportdocs`; do \
		${RM} -rf ${WRKSRC}/opt/${COMPILERDIR}/$$i; \
	done
.endif
# Allow everyone to use it.
	@${CHMOD} a+rx ${WRKSRC}/opt
# Remove unneeded/unsafe access rights.
.for i in doc include lib
	@${FIND} ${WRKSRC}/opt/${COMPILERDIR}/${i} -type f -print0 | \
		${XARGS} -0 ${CHMOD} a-x,og-w
.endfor
	@${FIND} ${WRKSRC}/opt -type d -print0 | ${XARGS} -0 ${CHMOD} go-w
	@${CHMOD} a-x ${WRKSRC}/opt/${COMPILERDIR}/bin/Errormatch.txt

post-patch:
# Correct some paths and patch some files
.for i in icc iccvars.csh iccvars.sh icpc
	@${REINPLACE_CMD} -i "" -e 's:%%ICC_LOCALBASE%%:${LOCALBASE}:g; \
		s:\<INSTALLDIR\>:${PREFIX}/${COMPILERDIR}:g; \
		s:man -w:manpath -q:g' ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
.if ${PORTVERSION} != ${PATCHLEVEL}
	@${REINPLACE_CMD} -i "" -e \
		's:\<installpackageid\>:${DISTNAME}_${PATCHLEVEL}:g' \
		${WRKSRC}/opt/${COMPILERDIR}/doc/csupport
.else
	@${REINPLACE_CMD} -i "" -e 's:\<installpackageid\>:${DISTNAME}:g' \
		${WRKSRC}/opt/${COMPILERDIR}/doc/csupport
.endif
	@${RM} ${WRKSRC}/opt/${COMPILERDIR}/include/*.orig
	@${RM} ${WRKSRC}/opt/${COMPILERDIR}/include/c++/*.orig
.for i in icc.orig icpc.orig
	@${RM} ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
# Provide a more FreeBSD'ish compile environment
.for i in icc.cfg icpc.cfg
	@${ECHO_CMD} -e "-no-gcc\n-Qlocation,ld,${PREFIX}/${COMPILERDIR}/bin/ldwrapper\n\n-wr1125\n-we140\n\n-Ulinux\n-U__linux__\n-U__linux\n-U__gnu_linux__\n\n-D__FreeBSD__=${ICCCFGVAL}\n\n" >>${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.if ( ${OSVERSION} >= 500039 )
	@${ECHO_CMD} -e "-D__wchar_t=__ct_rune_t\n" >>${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endif
.if ( ${OSVERSION} >= 502108 )
	@${ECHO_CMD} -e "-restrict\n" >>${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endif
	@${CHMOD} a-x,g-w ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
# C++ hack for icpc
	@${ECHO_CMD} -e "\n-I${PREFIX}/include/stlport\n-Qoption,ld,-CPLUSPLUS\n" \
		>>${WRKSRC}/opt/${COMPILERDIR}/bin/icpc.cfg
	@cd ${WRKSRC}/opt/${COMPILERDIR}/bin/ && ${LN} -s icc.cfg iccbin.cfg \
		&& ${LN} -s icpc.cfg icpcbin.cfg
# Hack while there's no support for icc in the stdarg.h and sys/cdefs.h.
.if ( ${OSVERSION} < 502108 )
	@${CP} ${FILESDIR}/stdarg.h ${WRKSRC}/opt/${COMPILERDIR}/include
	@${MKDIR} ${WRKSRC}/opt/${COMPILERDIR}/include/sys
	@${CP} ${FILESDIR}/cdefs.h ${WRKSRC}/opt/${COMPILERDIR}/include/sys
.endif

.if ( ${OSVERSION} >= 470101 && ${OSVERSION} < 500000 ) || \
	( ${OSVERSION} >= 500042 )
OBJCOPY_OPS=	--redefine-sym stdin=__stdinp \
		--redefine-sym stdout=__stdoutp \
		--redefine-sym stderr=__stderrp
.endif

do-build:
# Use the Linux ABI for the binaries
.for i in codecov iccbin iccfilt icpcbin icpi mcpcom profmerge proforder tselect xiar xild
	@${BRANDELF} -t Linux ${WRKSRC}/opt/${COMPILERDIR}/bin/${i}
.endfor
# Fix unresolved references
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/assert_fail.c \
		${FILESDIR}/errno_location.c ${FILESDIR}/mcount.S
.if ( ${OSVERSION} < 502101 )
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/cxa_atexit.c
.endif
.if ( ${OSVERSION} < 470101 ) || \
	( ${OSVERSION} >= 500000 && ${OSVERSION} < 500042 )
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stdin.o ${FILESDIR}/stdin.c
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stdout.o ${FILESDIR}/stdout.c
	@${CC} ${CFLAGS} -c -o ${WRKSRC}/stderr.o ${FILESDIR}/stderr.c
.endif
.for i in libcxa.a libcxaguard.a libimf.a libirc.a libircmt.a libunwind.a
	@${OBJCOPY} --redefine-sym __sigsetjmp=sigsetjmp \
		${OBJCOPY_OPS} \
		${WRKSRC}/opt/${COMPILERDIR}/lib/${i}
.endfor
	@${AR} q ${WRKSRC}/opt/${COMPILERDIR}/lib/libcxa.a ${WRKSRC}/*.o
	@${AR} q ${WRKSRC}/opt/${COMPILERDIR}/lib/libcxaguard.a ${WRKSRC}/*.o
# Some magic to be able to link
	@${MKDIR} ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper
	@${CC} ${CFLAGS} -o \
		${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld \
		${FILESDIR}/ld.c
	@${STRIP_CMD} ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld
	@${CHMOD} 755 ${WRKSRC}/opt/${COMPILERDIR}/bin/ldwrapper/ld

do-install:
	@cd ${WRKSRC}/opt && ${FIND} . -print | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${PREFIX}

post-install:
	@${ECHO} "${PKGNAME} is now installed in ${PREFIX}/${COMPILERDIR}, to use it you have to"
	@${ECHO} "put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO} "${PREFIX}/${COMPILERDIR}/licenses) directory and add"
	@${ECHO} "${PREFIX}/${COMPILERDIR}/bin to your PATH."
	@${ECHO}
	@${ECHO} "In order to be able to compile C++ source with icpc you have to install"
	@${ECHO} "devel/stlport-icc."
	@${ECHO}
	@${ECHO} "If you use icc on a Pentium 4 make sure you have 'options CPU_ENABLE_SSE'"
	@${ECHO} "in your kernel config (have a look at http://www.FreeBSD.org/handbook/"
	@${ECHO} "if you do not know how to do this), else icc will hang forever."
	@${ECHO}
	@${ECHO} "WARNING: If you use icc while having linux_devtools installed, icc will use"
	@${ECHO} "the wrong includes and therefore will generate bogus (not working) binaries!"
	@${ECHO}
	@${ECHO} "If you encounter further problems with icc please consult the errata at"
	@${ECHO} "http://support.intel.com/support/performancetools/c/C_Compiler_Errata.htm"
	@${ECHO} "first."
	@${ECHO}
	@${ECHO} "Call for benchmarks:"
	@${ECHO} "Intel is interested to see some benchmark numbers which compare gcc with icc."
	@${ECHO} "If you have a CPU produced by Intel and are able to do benchmarks with"
	@${ECHO} "either your own source or with one of our major ports (e.g. with"
	@${ECHO} "a webserver, a mailserver, a database system, an important graphics"
	@${ECHO} "suite/program or some important math tool, ...) please try to spend some time"
	@${ECHO} "to do a benchmark and send me (${MAINTAINER}) the result. You should"
	@${ECHO} "include your system specs (CPU: speed/model, RAM: amount/speed, used disks"
	@${ECHO} "(if necessary), chipset/mainboard type, ...), the version of the used"
	@${ECHO} "software (OS, gcc, icc, ...), non default tuning options (kernel, sysctl) and"
	@${ECHO} "the used compiler switches. If you don't use some 'standard' benchmark"
	@${ECHO} "(e.g. the official MySQL benchmark, or the performance test suite of your"
	@${ECHO} "prefered scripting language), please include a description about the"
	@${ECHO} "benchmark too."
	@${ECHO}
	@${ECHO} "Please use FreeBSD as the name of your OS in communications with the support,"
	@${ECHO} "the larger the FreeBSD userbase is, the more work gets done on FreeBSD"
	@${ECHO} "specific issues by Intel. And please thank them for the FreeBSD support,"
	@${ECHO} "they are already spending some time to improve icc on FreeBSD."
	@${ECHO}
	@${ECHO} "To read the entire post install message again, just run"
	@${ECHO} "'make post-install | less'."

.include <bsd.port.post.mk>
