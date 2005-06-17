# New ports collection makefile for:    ifc
# Date created:         Oct 30, 2001
# Whom:                 chat95@mbox.kyoto-inet.or.jp
#
# $FreeBSD$
#

PORTNAME=	ifc7
PORTVERSION=	7.1.040
PORTREVISION=	1
CATEGORIES=	lang linux devel
MASTER_SITES=
DISTNAME=	l_fc_pc_${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Intel's Fortran compiler, set up to produce native FreeBSD objects

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

RESTRICTED=	Intel forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=		i386

USE_LINUX=		yes
USE_REINPLACE=		yes
NO_WRKSUBDIR=		yes

COMPILERDIR=	compiler70
PLIST_SUB=	COMPILERDIR=${COMPILERDIR}
PATCH_WRKSRC=	${WRKSRC}/opt/intel/${COMPILERDIR}

MAN1=		ifc.1
MANPREFIX=	${PREFIX}/intel/${COMPILERDIR}/

IFC_SITE=	http://www.intel.com/software/products/compilers/

.include <bsd.port.pre.mk>

EXTRACT_AFTER_ARGS=	| tar -xf - \
			--exclude intel-iidb\*.rpm \
			--exclude \*ia64.rpm \
			--exclude flexlm64

IFCCFGVAL!=	${UNAME} -r | ${SED} -e 's/\..*//'

.for file in ${DISTNAME}
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${file}${EXTRACT_SUFX})
IGNORE=	"Go to Intel Premier Support, https://premier.intel.com, to obtain ${DISTFILES}. Product updates such as this compiler are posted regularly on Premier Support. You must have a license to obtain access to Premier Support. If you do not already have a license go to ${IFC_SITE} to review licensing options \(evaluation, commercial, and free non-commercial\) and obtain a license. Put ${DISTFILES} into ${DISTDIR} and run make again"
.endif
.endfor

.if exists(${LINUXBASE}/boot/kernel.h) #|| \
#	exists(${PREFIX}/intel/compiler60/bin/icc) || \
#	exists(${PREFIX}/intel/compiler70/bin/icc)
BROKEN=	Cannot coexist with linux_devtools or icc
.endif

post-extract:
	@${SED} 's:%%COMPILERDIR%%:${COMPILERDIR}:' ${FILESDIR}/cpio-exclude \
		>${WRKDIR}/cpio-exclude
.if defined(NOPORTDOCS)
	@${SED} 's:%%COMPILERDIR%%:${COMPILERDIR}:' \
		${FILESDIR}/cpio-exclude_noportdocs >>${WRKDIR}/cpio-exclude
.endif
	@cd ${WRKSRC} && rpm2cpio.pl 2>/dev/null *.rpm | \
		${CPIO} -idfuE ${WRKDIR}/cpio-exclude --quiet

pre-patch:
# Allow everyone to use it
	@${CHMOD} a+rx ${WRKSRC}/opt
# Remove unneeded/unsafe access rights
.for i in docs ia32/include ia32/lib
	@${FIND} ${WRKSRC}/opt/intel/${COMPILERDIR}/${i} -type f -print0 | \
		${XARGS} -0 ${CHMOD} a-x,g-w
.endfor
	@${FIND} ${WRKSRC}/opt -type d -print0 | ${XARGS} -0 ${CHMOD} go-w
# Use the Linux ABI for the binaries
.for i in ifcbin fpp icid f90com profmerge proforder xiar xild
	@${BRANDELF} -t Linux ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor

post-patch:
# Correct some paths and patch some files
.for i in ia32/bin/ifc ia32/bin/ifcvars.csh ia32/bin/ifcvars.sh
	@${REINPLACE_CMD} -i "" -e 's:%%ICC_LOCALBASE%%:${LOCALBASE}:g; \
		s@\<INSTALLDIR\>@${PREFIX}/intel@g; s@man -w@manpath -q@g' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/${i}
	@${CHMOD} 755 ${WRKSRC}/opt/intel/${COMPILERDIR}/${i}
.endfor
	@${REINPLACE_CMD} -i "" -e 's:\<INSTALLTIMECOMBOPACKAGEID\>:${DISTNAME}:g' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/docs/fsupport
.for i in ifc.orig
	@${RM} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor
# Provide a more FreeBSD'ish compile environment
.for i in ifc.cfg
	@${REINPLACE_CMD} -i "" -e 's:-Xlinker -rpath -Xlinker <INSTALLDIR>/${COMPILERDIR}/ia32/lib::g' \
		-e 's@\<INSTALLDIR\>@${PREFIX}/intel@g;' \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
	@${ECHO_CMD} -e "-Qlocation,ld,${PREFIX}/intel/${COMPILERDIR}/ia32/bin/ldwrapper\n\n-Ulinux\n-U__linux__\n-U__linux\n-U__gnu_linux__\n\n-D__FreeBSD__=${IFCCFGVAL}\n-D__ELF__=1\n" >>${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.if ${OSVERSION} < 500016
	@${ECHO_CMD} -e "-Qoption,ld,-MT\n" >>${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endif
	@${CHMOD} a-x,g-w ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/${i}
.endfor
	@cd ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ && ${LN} -s ifc.cfg ifcbin.cfg

.if ( ${OSVERSION} >= 470101 && ${OSVERSION} < 500000 ) || \
	( ${OSVERSION} >= 500042 )
OBJCOPY_OPS=	--redefine-sym stdin=__stdinp \
		--redefine-sym stdout=__stdoutp \
		--redefine-sym stderr=__stderrp
.endif

do-build:
# Fix unresolved references
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -c ${FILESDIR}/assert_fail.c \
		${FILESDIR}/linux_file.c ${FILESDIR}/linux_stat.c \
		${FILESDIR}/mmap.c       ${FILESDIR}/pthread.c \
		${FILESDIR}/sysconf.c    \
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
.for i in libcxa.a libimf.a libirc.a libircmt.a libunwind.a \
	libBINDF90.a libCEPCF90.a libF90.a libIEPCF90.a libPEPCF90.a \
	libcprts.a libintrins.a libompstub.a
	@${OBJCOPY} --redefine-sym __sigsetjmp=sigsetjmp \
		${OBJCOPY_OPS} \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/lib/${i}
.endfor
	@cd ${WRKSRC} && ${AR} x /usr/lib/libcompat.a ftime.o
	@${AR} q ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/lib/libcxa.a ${WRKSRC}/*.o
.for i in BINDF90 PEPCF90 CEPCF90 POSF90 IEPCF90
	@${OBJCOPY} --strip-symbol=stat \
		--strip-symbol=fstat \
		--strip-symbol=lstat \
		--redefine-sym lseek=l_lseek \
		--redefine-sym lseek64=lseek \
		--redefine-sym open64=open \
		--redefine-sym creat64=creat \
		--redefine-sym ftruncate64=ftruncate \
		--redefine-sym mmap=Mmap \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/lib/lib${i}.a
.endfor
# Some magic to be able to link
	@${MKDIR} ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper
	@${CC} ${CFLAGS} -o \
		${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld \
		${FILESDIR}/ld.c
# We can't use STRIP_CMD, since we need the FreeBSD one, not the Linux one.
	@/usr/bin/strip ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld
	@${CHMOD} 755 ${WRKSRC}/opt/intel/${COMPILERDIR}/ia32/bin/ldwrapper/ld

do-install:
	@cd ${WRKSRC}/opt && ${FIND} . -print | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${PREFIX}

post-install:
	@${ECHO} "${PKGNAME} is now installed in ${PREFIX}/intel, to use it you have to"
	@${ECHO} "put your license into your \$${INTEL_FLEXLM_LICENSE} (default:"
	@${ECHO} "${PREFIX}/intel/licenses) directory and add"
	@${ECHO} "${PREFIX}/intel/${COMPILERDIR}/ia32/bin to your PATH."
	@${ECHO}
	@${ECHO} "If you use ifc on a Pentium 4 make sure you have 'options CPU_ENABLE_SSE'"
	@${ECHO} "in your kernel config (have a look at http://www.FreeBSD.org/handbook/"
	@${ECHO} "if you do not know how to do this), else ifc will hang forever."
	@${ECHO}
	@${ECHO} "WARNING: If you use ifc while having linux_devtools installed, ifc will use"
	@${ECHO} "the wrong includes and therefore will generate bogus (not working) binaries!"
	@${ECHO}
	@${ECHO} "If you encounter further problems with ifc please consult the errata at"
	@${ECHO} "http://support.intel.com/support/performancetools/fortran/linux/"
	@${ECHO} "first."

.include <bsd.port.post.mk>
